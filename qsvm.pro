#-------------------------------------------------
#
# Project created by QtCreator 2012-12-15T13:10:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qsvm
TEMPLATE = app

INCLUDEPATH += qcustomplot

win32 {
    INCLUDEPATH += c:/dev/include
#    INCLUDEPATH += c:/qt/qt-4.8.4
#    INCLUDEPATH += c:/qt/qt-4.8.4/4.8.4-qt-x86
    win32-g++:LIBS += c:/dev/lib/libsvm.dll
}

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot/qcustomplot.cpp \
    svm_classifier.cpp

HEADERS  += mainwindow.h \
    qcustomplot/qcustomplot.h \
    svm_classifier.h



FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11


