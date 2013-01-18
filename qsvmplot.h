#ifndef PLOT_H
#define PLOT_H

#include "qcustomplot.h"
#include "svm_classifier.h"
#include <memory>

class QSVMPlot : public QCustomPlot
{
    Q_OBJECT
public:
    QSVMPlot(QWidget* parent =0);
    ~QSVMPlot();

    void update();

    void setClassifier(svm_classifier *cls) {
        classifier = std::shared_ptr<svm_classifier>(cls);
    }

private:
    QColor colors[5] = { Qt::red, Qt::blue, Qt::green, Qt::magenta, Qt::cyan };


    /// the plot needs to share a pointer to the classifier because when plotting the classification border,
    /// it needs to call classifier_predict() for points corresponding to pixels on screen
    std::shared_ptr<svm_classifier> classifier;
};

#endif // PLOT_H
