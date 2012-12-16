#ifndef SVM_CLASSIFIER_H
#define SVM_CLASSIFIER_H

#include <vector>
#include <libsvm/svm.h>

class svm_classifier {
public:
    svm_classifier();
    ~svm_classifier();

    bool load_data(const char* filename);
    bool load_model(const char* filename);
    void train();
    void cross_validate(int nfold);
    const svm_model* model() const { return model_; }
    const svm_problem& problem() const { return problem_; }
    const std::vector<std::vector<double> >& samples() const { return samples_; }

    int nfeatures() const { return samples_.front().size()-1; }

private:
    std::vector<std::vector<double> > samples_; // to store the raw samples (because the svm_problem
                                                // uses a sparse format and will discard 0 values)
    svm_problem problem_;
    svm_parameter param_;
    svm_model *model_;

    // because it's easier to manage vectors instead of simple arrays
    std::vector<svm_node> inputs_;
    std::vector<svm_node*> rows_;
    std::vector<double> labels_;

    void get_samples(const char* filename);
};

#endif // SVM_CLASSIFIER_H
