#include "qsvmplot.h"
#include "mainwindow.h"

using namespace std;

QSVMPlot::QSVMPlot(QWidget* parent)
{
}

QSVMPlot::~QSVMPlot() {
}

void
QSVMPlot::update() {
    qDebug() << "Update";

    if (classifier->samples().size() == 0) {
        qDebug() << "Error: insufficient samples";
        return;
    }

    int n = classifier->nfeatures();

    QVector<QCPDataMap*> classes;

    for (int i = 0; i != n; ++i) { classes.append(new QCPDataMap); }

    qDebug() << "Before samples";

    auto samples = classifier->samples();
    for (auto s : samples) {
        classes[s[0] < 0 ? 0 : 1]->insertMulti(s[1], QCPData(s[1], s[2]));
    }

    // plot first class of points in red
    clearGraphs();

    qDebug() << "Clear graphs";

    for (int i = 0; i != n; ++i) {
        auto graph = addGraph();
        graph->setPen(QPen(colors[i]));
        graph->setLineStyle(QCPGraph::lsNone);
        graph->setScatterStyle(QCP::ssDisc);
        graph->setScatterSize(5);
        graph->setAntialiasedScatters(true);
        graph->setErrorType(QCPGraph::etValue);
        graph->setErrorPen(QPen(QColor(180,180,180)));
        graph->keyAxis()->setRange(0.0, 1.0);
        graph->valueAxis()->setRange(0.0, 1.0);
        graph->setData(classes[i]);
        graph->setName("Class " + QString::number(i));
    }

    // plot support vectors and classification border
    if (classifier->model() != nullptr) {
        auto supportVectors = classifier->model()->SV;
        auto graph = addGraph();
        graph->setPen(QPen(Qt::black));
        graph->setLineStyle(QCPGraph::lsNone);
        graph->setScatterStyle(QCP::ssCircle);
        graph->setScatterSize(12);
        graph->setName("Support vectors");
        auto data = new QCPDataMap;

        for (int i = 0; i != classifier->model()->l; ++i) {
            svm_node *sv = supportVectors[i];
            double x = sv[0].value, y = sv[1].value;
            data->insertMulti(x, QCPData(x,y));
        }
        graph->setData(data);

        int w = this->graph(0)->keyAxis()->coordToPixel(graph->keyAxis()->range().upper);
        int h = this->graph(0)->valueAxis()->coordToPixel(graph->valueAxis()->range().lower);

        qDebug() << "w: " << w << ", h: " << h;
        qDebug() << "w: " << this->axisRect().width() << ", h: " << this->axisRect().height();

        QImage image(w, h, QImage::Format_ARGB32);
        image.fill(Qt::transparent);

        for (int l = 0; l != h; ++l) {
            auto line = (QRgb*)image.scanLine(l);
            for (int i = 0; i != w; ++i) {
                double x = (double)i / w;
                double y = (double)l / h;
                svm_node sv[3] = { {1, x } , { 2, y }, { -1, -0.0 } };
                double d = classifier->predict(sv);
                line[i] = d < 0 ? qRgba(255, 0, 0, 50) : qRgba(0, 0, 255, 50);
            }
        }

        QCPItemRect *rect;
        if (this->itemCount() == 0) {
            rect = new QCPItemRect(this);
            addItem(rect);
        }
        else {
            rect = (QCPItemRect*)this->item(0);
        }
        auto brush = QBrush(image.mirrored(false, true));
        rect->setBrush(brush);
        rect->topLeft->setCoords(0, 0);
        rect->bottomRight->setCoords(1, 1);
//        rect->topLeft->setCoords(graph->keyAxis()->pixelToCoord(xmin), 0);
//        rect->bottomRight->setCoords(graph->keyAxis()->pixelToCoord(xmax), 1);
    }

    legend->setVisible(true);
    setupFullAxesBox();
    replot();
}

