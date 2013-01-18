#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtCore/QThread>
#include "svm_classifier.h"
#include "qsvmplot.h"
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class UpdatePlotThread;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_inputDataLoaded(QString& filename);
    void on_action_LoadModel_triggered();
    void on_action_TrainModel_triggered();
    void on_tabWidget_currentChanged(int index);
    void on_loadTrainDataButton_clicked();

    void on_kernelTypeComboBox_currentIndexChanged(int index);
    void on_svmTypeComboBox_currentIndexChanged(int index);


private:
    Ui::MainWindow *ui;
    std::shared_ptr<svm_classifier> classifier;


    void updateTable();
    void resizeTable();
    void validateParameters();

signals:
    void inputDataLoaded(QString& filename);
};
#endif // MAINWINDOW_H
