QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = qsvm
TEMPLATE = app

INCLUDEPATH += qcustomplot

win32 {
    INCLUDEPATH += c:/dev/include
    LIBS += c:/dev/lib/libsvm.dll
}

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot/qcustomplot.cpp \
    svm_classifier.cpp \
    qsvmplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot/qcustomplot.h \
    svm_classifier.h \
    qsvmplot.h



FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11 -O2 -march=native
#QMAKE_CXXFLAGS += -g -std=c++11


