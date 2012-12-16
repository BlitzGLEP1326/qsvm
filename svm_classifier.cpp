#include "svm_classifier.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <numeric>
#include <algorithm>

using namespace std;

namespace {
struct split
{
    enum empties_t { empties_ok, no_empties };
};
}

namespace util {
vector<string>& split_string(vector<string>&            result,
                             const string&              s,
                             const string&              delimiters,
                             split::empties_t empties = split::empties_ok)
{
    result.clear();
    size_t current;
    size_t next = -1;
    do {
        if (empties == split::no_empties) {
            next = s.find_first_not_of( delimiters, next + 1 );
            if (next == string::npos) break;
            next -= 1;
        }
        current = next + 1;
        next = s.find_first_of( delimiters, current );
        result.push_back( s.substr( current, next - current ) );
    }
    while (next != string::npos);
    return result;
}
}

svm_classifier::svm_classifier() : model_(0) {
    // set some defaults
    param_.svm_type = C_SVC;
//    param_.svm_type = EPSILON_SVR;
    param_.kernel_type = RBF;
    param_.degree = 3;
    param_.gamma = 0;	// 1/num_features
    param_.coef0 = 0;
    param_.nu = 0.5;
    param_.cache_size = 100;
    param_.C = 1;
    param_.eps = 1e-3;
    param_.p = 0.1;
    param_.shrinking = 1;
    param_.probability = 0;
    param_.nr_weight = 0;
    param_.weight_label = 0;
    param_.weight = 0;
}

svm_classifier::~svm_classifier() {
    if(model_ != 0) svm_free_and_destroy_model(&model_);
    svm_destroy_param(&param_);
}

void svm_classifier::get_samples(const char *filename) {
    samples_.clear();
    ifstream istr(filename);
    if (!istr.is_open()) {
        throw "Coult not open file";
    }
    string line;
    while(std::getline(istr, line)) {
        vector<string> fields;
        util::split_string(fields, line, " ");
        vector<double> values;
        for (auto it = begin(fields); it != end(fields); ++it) {
            vector<string> tokens;
            util::split_string(tokens, *it, ":");
            values.push_back(atof(tokens.back().c_str()));
        }
        samples_.push_back(values);
        values.clear();
    }
}

bool // returns true if it was able to load data from the file, otherwise false
svm_classifier::load_data(const char* filename) {
    try {
        get_samples(filename);
    }
    catch (string &err) {
        cerr << "Coult not get samples: " << err << endl;
        return false;
    }

    labels_.clear(); inputs_.clear(); rows_.clear();
    int maxindex = 0;
    for_each(begin(samples_), end(samples_), [&maxindex](vector<double>& v){ if (maxindex < v.size()) maxindex = v.size(); });
    --maxindex; // because the first column is actually the labels

    if (param_.gamma == 0 && maxindex > 0)
        param_.gamma = 1.0 / maxindex;

    // go over samples matrix and convert values into svm sparse-format node matrix (see libSVM README)
    // here we assume the labels are always in the first column
    for (auto s : samples_) {
        labels_.push_back(s[0]);
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] == 0) continue;
            inputs_.push_back(svm_node{ i, s[i] });
        }
        inputs_.push_back(svm_node {-1, -0.0 }); // index=-1 indicates the end of one vector (see libSVM README)
    }

    // update the problem
    problem_.l = labels_.size();
    problem_.y = labels_.data();

    auto it = begin(inputs_);
    while (it->index == -1) ++it; // just paranoid
    rows_.push_back(&(*it));

    if ((end(inputs_)-1)->index != -1) {
        cerr << "Warning: possibly corrupted input (last index = " << end(inputs_)->index << ")" << endl;
    }
    for (; it != end(inputs_)-1; ++it) {
        if (it->index == -1) {
            rows_.push_back(&(*(++it))); // pretty cool :)
        }
    }
    problem_.x = rows_.data();

    return true;
}

bool
svm_classifier::load_model(const char *filename) {
    model_ = svm_load_model(filename);
    return true; // if the model was loaded successfully
}

void
svm_classifier::train() {
    model_ = svm_train(&problem_, &param_);
}

void svm_classifier::cross_validate(int nfold) {
    int total_correct = 0, length = problem_.l;
    double total_error = 0;
    vector<double> target(length);
    svm_cross_validation(&problem_, &param_, nfold, target.data());

    if (param_.svm_type == EPSILON_SVR || param_.svm_type == NU_SVR) {
        double sumv = 0, sumy = 0, sumvv = 0, sumyy = 0, sumvy = 0;
        for (int i = 0; i != length; ++i) {
            double y = labels_[i];
            double v = target[i];
            total_error += (v-y)*(v-y);
            sumv += v;
            sumy += y;
            sumvv += v*v;
            sumyy += y*y;
            sumvy += v*y;
        }
        double mse = total_error / length;
        double scc = ( (length * sumvy - sumv * sumy) * (length * sumvy - sumv * sumy) ) /
                     ( (length * sumvv - sumv * sumv) * (length * sumyy - sumy * sumy) );
        cout << "Cross Validation Mean squared error = " << mse << endl;
        cout << "Cross Validation Squared correlation coefficient = " << scc << endl;
    } else {
        for (int i = 0; i != length; ++i) {
            if (target[i] == labels_[i]) ++total_correct;
        }
        double acc = 100.0 * total_correct / length;
        cout << "Cross validation accuracy = " << acc << endl;
    }
}

