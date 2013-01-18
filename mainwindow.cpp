#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    classifier = std::make_shared<svm_classifier>();
    ui->plotArea->setClassifier(classifier.get());
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setFont(QFont("Consolas"));


    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 0);

    // map signals to slots
    connect(this, &MainWindow::inputDataLoaded, this, &MainWindow::on_inputDataLoaded);
    connect(ui->action_Quit, &QAction::triggered, &QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_LoadModel_triggered()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    QString selectedFile;
    if (dialog.exec()) {
        selectedFile = dialog.selectedFiles()[0];
        if (classifier->load_model(selectedFile.toStdString().c_str())) {
            ui->plotArea->update();
        }
    }
}

void MainWindow::validateParameters() {
    // update parameters with values from the interface
    bool ok = false;
    if (ui->svmParamCLineEdit->isEnabled()) {
        double param_C = ui->svmParamCLineEdit->text().toDouble(&ok);
        if (!ok) {
            // handle conversion error
            ui->textEdit->append("Could not convert C param value. Using default.");
            param_C = 1.0;
        } else {
            classifier->parameters().C = param_C;
            ui->svmParamCLineEdit->setText(QString::number(param_C));
        }
    }
    if (ui->svmParamDegreeLineEdit->isEnabled()) {
        int param_Degree = ui->svmParamDegreeLineEdit->text().toInt(&ok);
        if (!ok) {
            // handle conversion error
            ui->textEdit->append("Could not convert Degree param value. Using default.");
            param_Degree = 3;
        } else {
            classifier->parameters().degree = param_Degree;
            ui->svmParamDegreeLineEdit->setText(QString::number(param_Degree));
        }
    }
}

void MainWindow::on_action_TrainModel_triggered() {
    this->validateParameters();

    classifier->train();
    auto model = classifier->model();
    // update console log
    ui->textEdit->append("Training complete.");
    ui->textEdit->append("Number of support vectors: " + QString::number(model->l));
    for (int i = 0; i != model->nr_class; ++i) {
        ui->textEdit->append("\t" + QString::number(model->nSV[i]) + " in Class " + QString::number(i+1));
    }
    // update plot
    ui->plotArea->update();
}

void MainWindow::on_loadTrainDataButton_clicked() {
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    if (dialog.exec()) {
        auto selectedFile = dialog.selectedFiles()[0];
        if (classifier->load_data(selectedFile.toStdString().c_str())) {
            emit inputDataLoaded(selectedFile);
        }
    }
}

void MainWindow::on_inputDataLoaded(QString& filename) {
    ui->textEdit->append("Loaded " + QString::number(classifier->samples().size()) + " samples from " + filename);
    ui->action_TrainModel->setEnabled(true);

    ui->hSplitter->show();

    updateTable();
    ui->plotArea->update();
}

void MainWindow::on_tabWidget_currentChanged(int index) {
    if (index == ui->tabWidget->indexOf(ui->datasetTab)) {
        if (ui->tableWidget->rowCount() == 0) {
            ui->hSplitter->hide();
        } else {
            resizeTable();
        }
    }
}

void MainWindow::updateTable() {
    auto samples = classifier->samples();
    ui->tableWidget->setRowCount(samples.size());
    ui->tableWidget->setColumnCount(samples[0].size());
    // add items to the table
    for (unsigned i = 0; i != samples.size(); ++i) {
        for (unsigned j = 0; j != samples[i].size(); ++j) {
            ui->tableWidget->setHorizontalHeaderItem(j, new QTableWidgetItem("X" + QString::number(j)));
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(samples[i][j], 'f')));
            ui->tableWidget->item(i, j)->setTextAlignment(Qt::AlignRight);
        }
    }
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Y"));
    this->resizeTable();
}

void MainWindow::resizeTable() {
    ui->tableWidget->resizeColumnsToContents();
    int width = 4; // to account for margins
    for (int j = 0; j != ui->tableWidget->columnCount(); ++j) {
        width += ui->tableWidget->columnWidth(j);
    }
    int oldWidth = ui->tableWidget->width();

    QList<int> sizes(ui->hSplitter->sizes());
    sizes[0] += width - oldWidth;
    sizes[1] += oldWidth - width;
    sizes.append(width - oldWidth + ui->tableWidget->width());
    sizes.append(oldWidth - width + ui->plotArea->width());
    ui->hSplitter->setSizes(sizes);
}

void MainWindow::on_kernelTypeComboBox_currentIndexChanged(int index) {
    if (index == POLY) {
        ui->svmParamDegreeLabel->setEnabled(true);
        ui->svmParamDegreeLineEdit->setEnabled(true);
    } else {
        ui->svmParamDegreeLabel->setEnabled(false);
        ui->svmParamDegreeLineEdit->setEnabled(false);
    }
    classifier->parameters().kernel_type = index;
}

void MainWindow::on_svmTypeComboBox_currentIndexChanged(int index)
{
    if (index == C_SVC || index == EPSILON_SVR || index == NU_SVR) {
        ui->svmParamCLabel->setEnabled(true);
        ui->svmParamCLineEdit->setEnabled(true);
    } else {
        ui->svmParamCLabel->setEnabled(false);
        ui->svmParamCLineEdit->setEnabled(false);
    }
    classifier->parameters().svm_type = index;
}
