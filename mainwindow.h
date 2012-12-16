#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "svm_classifier.h"

#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_input_data_loaded();
    void on_action_LoadModel_triggered();
    void on_action_TrainModel_triggered();
    void on_tabWidget_currentChanged(int index);
    void on_loadTrainDataButton_clicked();

private:
    Ui::MainWindow *ui;
//    std::unique_ptr<svm_classifier> classifier;
    svm_classifier *classifier;

    void updateTable();
    void resizeTable();
    void updatePlot();

signals:
    void input_data_loaded();
};

#endif // MAINWINDOW_H
