#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QList>

#include <iostream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    classifier = new svm_classifier;

    ui->textEdit->setReadOnly(true);
    ui->textEdit->setFont(QFont("Consolas"));

    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 0);

    // map signals to slots
    connect(this, SIGNAL(input_data_loaded()), this, SLOT(on_input_data_loaded()));
    connect(ui->action_Quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete classifier;
}

void MainWindow::on_action_LoadModel_triggered()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    QString selectedFile;
    if (dialog.exec()) {
        selectedFile = dialog.selectedFiles()[0];
        if (classifier->load_data(selectedFile.toStdString().data())) {
            emit input_data_loaded();
            if (classifier->load_model(selectedFile.toStdString().c_str())) {
                // do something with the model
            }
        }
    }
}

void MainWindow::on_action_TrainModel_triggered() {
    classifier->train();
    auto model = classifier->model();
    ui->textEdit->append("Training complete.");
    ui->textEdit->append("Number of support vectors: " + QString::number(model->l));
    for (int i = 0; i != model->nr_class; ++i) {
        ui->textEdit->append("\t" + QString::number(model->nSV[i]) + " in Class " + QString::number(i+1));
    }
}

void MainWindow::on_loadTrainDataButton_clicked()
{
    qDebug() << "Load train data";
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    if (dialog.exec()) {
        auto selectedFile = dialog.selectedFiles()[0];
        if (classifier->load_data(selectedFile.toStdString().c_str())) {
            emit input_data_loaded();
        }
    }
}

void MainWindow::on_input_data_loaded() {
    ui->textEdit->append("Loaded " + QString::number(classifier->samples().size()) + " samples.");
    ui->centralWidget->show();
    ui->action_TrainModel->setEnabled(true);

    ui->hSplitter->show();

    updateTable();
    updatePlot();
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
    resizeTable();
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

void MainWindow::updatePlot() {
    auto plot = ui->plotArea;
    QVector<double> neg_x0, neg_x1; // negative class
    QVector<double> pos_x0, pos_x1; // positive class
    auto samples = classifier->samples();
    for (auto s: samples) {
        if (s[0] < 0) {
            neg_x0.append(s[1]);
            neg_x1.append(s[2]);
        } else if (s[0] > 0) {
            pos_x0.append(s[1]);
            pos_x1.append(s[2]);
        }
    }
    // plot first class of points in red
    plot->clearGraphs();
    QCPGraph* graph;
    graph = plot->addGraph();
    graph->setPen(QPen(Qt::red));
    graph->setLineStyle(QCPGraph::lsNone);
    graph->setScatterStyle(QCP::ssDisc);
    graph->setScatterSize(4);
    graph->setAntialiasedScatters(true);
    graph->setErrorType(QCPGraph::etValue);
    graph->setErrorPen(QPen(QColor(180,180,180)));
    graph->setName("Negative class");
    graph->setData(neg_x0, neg_x1);
    // manually scale between [0,1]
    graph->keyAxis()->setRange(0.0, 1.0);
    graph->valueAxis()->setRange(0.0, 1.0);
    // plot second class of points in blue
    graph = plot->addGraph();
    graph->setPen(QPen(Qt::blue));
    graph->setLineStyle(QCPGraph::lsNone);
    graph->setScatterStyle(QCP::ssDisc);
    graph->setScatterSize(4);
    graph->setAntialiasedScatters(true);
    graph->setErrorType(QCPGraph::etValue);
    graph->setErrorPen(QPen(QColor(180,180,180)));
    graph->setName("Positive class");
    graph->setData(pos_x0, pos_x1);
    graph->keyAxis()->setRange(0.0, 1.0);
    graph->valueAxis()->setRange(0.0, 1.0);

    plot->legend->setVisible(true);
    plot->setupFullAxesBox();
    plot->replot();
}
