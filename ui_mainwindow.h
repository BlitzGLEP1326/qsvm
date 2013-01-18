/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jan 11 09:48:33 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qsvmplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quit;
    QAction *action_LoadModel;
    QAction *action_TrainModel;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *parametersTab;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QComboBox *svmTypeComboBox;
    QLabel *svmParamCLabel;
    QLineEdit *svmParamCLineEdit;
    QLabel *label_2;
    QComboBox *kernelTypeComboBox;
    QLabel *svmParamDegreeLabel;
    QLineEdit *svmParamDegreeLineEdit;
    QWidget *datasetTab;
    QGridLayout *gridLayout_2;
    QToolButton *loadTrainDataButton;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QSplitter *hSplitter;
    QTableWidget *tableWidget;
    QFrame *plotFrame;
    QGridLayout *gridLayout;
    QSVMPlot *plotArea;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1161, 701);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_LoadModel = new QAction(MainWindow);
        action_LoadModel->setObjectName(QStringLiteral("action_LoadModel"));
        action_TrainModel = new QAction(MainWindow);
        action_TrainModel->setObjectName(QStringLiteral("action_TrainModel"));
        action_TrainModel->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        parametersTab = new QWidget();
        parametersTab->setObjectName(QStringLiteral("parametersTab"));
        frame_2 = new QFrame(parametersTab);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 0, 300, 66));
        frame_2->setMaximumSize(QSize(300, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        svmTypeComboBox = new QComboBox(frame_2);
        svmTypeComboBox->setObjectName(QStringLiteral("svmTypeComboBox"));

        gridLayout_6->addWidget(svmTypeComboBox, 0, 1, 1, 1);

        svmParamCLabel = new QLabel(frame_2);
        svmParamCLabel->setObjectName(QStringLiteral("svmParamCLabel"));
        svmParamCLabel->setEnabled(true);
        svmParamCLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(svmParamCLabel, 0, 2, 1, 1);

        svmParamCLineEdit = new QLineEdit(frame_2);
        svmParamCLineEdit->setObjectName(QStringLiteral("svmParamCLineEdit"));
        svmParamCLineEdit->setEnabled(true);

        gridLayout_6->addWidget(svmParamCLineEdit, 0, 3, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_6->addWidget(label_2, 1, 0, 1, 1);

        kernelTypeComboBox = new QComboBox(frame_2);
        kernelTypeComboBox->setObjectName(QStringLiteral("kernelTypeComboBox"));

        gridLayout_6->addWidget(kernelTypeComboBox, 1, 1, 1, 1);

        svmParamDegreeLabel = new QLabel(frame_2);
        svmParamDegreeLabel->setObjectName(QStringLiteral("svmParamDegreeLabel"));
        svmParamDegreeLabel->setEnabled(false);
        svmParamDegreeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(svmParamDegreeLabel, 1, 2, 1, 1);

        svmParamDegreeLineEdit = new QLineEdit(frame_2);
        svmParamDegreeLineEdit->setObjectName(QStringLiteral("svmParamDegreeLineEdit"));
        svmParamDegreeLineEdit->setEnabled(false);

        gridLayout_6->addWidget(svmParamDegreeLineEdit, 1, 3, 1, 1);

        tabWidget->addTab(parametersTab, QString());
        datasetTab = new QWidget();
        datasetTab->setObjectName(QStringLiteral("datasetTab"));
        gridLayout_2 = new QGridLayout(datasetTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        loadTrainDataButton = new QToolButton(datasetTab);
        loadTrainDataButton->setObjectName(QStringLiteral("loadTrainDataButton"));

        gridLayout_2->addWidget(loadTrainDataButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        frame = new QFrame(datasetTab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        hSplitter = new QSplitter(frame);
        hSplitter->setObjectName(QStringLiteral("hSplitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hSplitter->sizePolicy().hasHeightForWidth());
        hSplitter->setSizePolicy(sizePolicy);
        hSplitter->setAutoFillBackground(false);
        hSplitter->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255)"));
        hSplitter->setOrientation(Qt::Horizontal);
        tableWidget = new QTableWidget(hSplitter);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAlternatingRowColors(true);
        hSplitter->addWidget(tableWidget);
        tableWidget->verticalHeader()->setVisible(false);
        plotFrame = new QFrame(hSplitter);
        plotFrame->setObjectName(QStringLiteral("plotFrame"));
        plotFrame->setFrameShape(QFrame::StyledPanel);
        plotFrame->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(plotFrame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plotArea = new QSVMPlot(plotFrame);
        plotArea->setObjectName(QStringLiteral("plotArea"));

        gridLayout->addWidget(plotArea, 0, 0, 1, 1);

        hSplitter->addWidget(plotFrame);

        gridLayout_7->addWidget(hSplitter, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 2);

        tabWidget->addTab(datasetTab, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setAcceptRichText(false);

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1161, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(action_Quit);
        mainToolBar->addAction(action_LoadModel);
        mainToolBar->addAction(action_TrainModel);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Quit->setText(QApplication::translate("MainWindow", "Quit", 0));
        action_LoadModel->setText(QApplication::translate("MainWindow", "Load model", 0));
        action_TrainModel->setText(QApplication::translate("MainWindow", "Train model", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "SVM", 0));
        label->setText(QApplication::translate("MainWindow", "SVM Type", 0));
        svmTypeComboBox->clear();
        svmTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "C_SVC", 0)
         << QApplication::translate("MainWindow", "NU_SVC", 0)
         << QApplication::translate("MainWindow", "ONE_CLASS", 0)
         << QApplication::translate("MainWindow", "EPSILON_SVR", 0)
         << QApplication::translate("MainWindow", "NU_SVR", 0)
        );
        svmParamCLabel->setText(QApplication::translate("MainWindow", "C", 0));
        label_2->setText(QApplication::translate("MainWindow", "Kernel", 0));
        kernelTypeComboBox->clear();
        kernelTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Linear", 0)
         << QApplication::translate("MainWindow", "Polynomial", 0)
         << QApplication::translate("MainWindow", "Radial base", 0)
         << QApplication::translate("MainWindow", "Sigmoid", 0)
         << QApplication::translate("MainWindow", "Precomputed", 0)
        );
        svmParamDegreeLabel->setText(QApplication::translate("MainWindow", "Degree", 0));
        svmParamDegreeLineEdit->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(parametersTab), QApplication::translate("MainWindow", "Parameters", 0));
        loadTrainDataButton->setText(QApplication::translate("MainWindow", "Load train data", 0));
        tabWidget->setTabText(tabWidget->indexOf(datasetTab), QApplication::translate("MainWindow", "Data", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Console", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
