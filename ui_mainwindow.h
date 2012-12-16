/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Dec 17 00:06:19 2012
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "qcustomplot.h"

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
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label;
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
    QCustomPlot *plotArea;
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1161, 701);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_LoadModel = new QAction(MainWindow);
        action_LoadModel->setObjectName(QString::fromUtf8("action_LoadModel"));
        action_TrainModel = new QAction(MainWindow);
        action_TrainModel->setObjectName(QString::fromUtf8("action_TrainModel"));
        action_TrainModel->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        parametersTab = new QWidget();
        parametersTab->setObjectName(QString::fromUtf8("parametersTab"));
        frame_2 = new QFrame(parametersTab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 0, 165, 66));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        comboBox_2 = new QComboBox(frame_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_6->addWidget(comboBox_2, 1, 1, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_6->addWidget(label_2, 1, 0, 1, 1);

        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_6->addWidget(comboBox, 0, 1, 1, 1);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        tabWidget->addTab(parametersTab, QString());
        datasetTab = new QWidget();
        datasetTab->setObjectName(QString::fromUtf8("datasetTab"));
        gridLayout_2 = new QGridLayout(datasetTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        loadTrainDataButton = new QToolButton(datasetTab);
        loadTrainDataButton->setObjectName(QString::fromUtf8("loadTrainDataButton"));

        gridLayout_2->addWidget(loadTrainDataButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        frame = new QFrame(datasetTab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        hSplitter = new QSplitter(frame);
        hSplitter->setObjectName(QString::fromUtf8("hSplitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hSplitter->sizePolicy().hasHeightForWidth());
        hSplitter->setSizePolicy(sizePolicy);
        hSplitter->setAutoFillBackground(false);
        hSplitter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        hSplitter->setOrientation(Qt::Horizontal);
        tableWidget = new QTableWidget(hSplitter);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAlternatingRowColors(true);
        hSplitter->addWidget(tableWidget);
        tableWidget->verticalHeader()->setVisible(false);
        plotFrame = new QFrame(hSplitter);
        plotFrame->setObjectName(QString::fromUtf8("plotFrame"));
        plotFrame->setFrameShape(QFrame::StyledPanel);
        plotFrame->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(plotFrame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plotArea = new QCustomPlot(plotFrame);
        plotArea->setObjectName(QString::fromUtf8("plotArea"));

        gridLayout->addWidget(plotArea, 0, 0, 1, 1);

        hSplitter->addWidget(plotFrame);

        gridLayout_7->addWidget(hSplitter, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 2);

        tabWidget->addTab(datasetTab, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setAcceptRichText(false);

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1161, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        action_LoadModel->setText(QApplication::translate("MainWindow", "Load model", 0, QApplication::UnicodeUTF8));
        action_TrainModel->setText(QApplication::translate("MainWindow", "Train model", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "SVM", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Linear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Polynomial", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Radial base", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Sigmoid", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Precomputed", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "Kernel", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "C_SVC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "NU_SVC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ONE_CLASS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "EPSILON_SVR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "NU_SVR", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "SVM Type", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(parametersTab), QApplication::translate("MainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
        loadTrainDataButton->setText(QApplication::translate("MainWindow", "Load train data", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(datasetTab), QApplication::translate("MainWindow", "Data", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Console", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
