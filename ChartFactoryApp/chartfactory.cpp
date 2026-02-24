#include "chartfactory.h"
#include "qcustomplot/include/qcustomplot.h"
#include <QJsonArray>

QWidget* ChartFactory::createChart(const QJsonObject& json, QWidget* parent)
{
    QString type = json["chartType"].toString();

    // -------- LINE CHART --------
    if (type == "line")
    {
        QCustomPlot* plot = new QCustomPlot(parent);
        plot->addGraph();

        QJsonArray xArr = json["xData"].toArray();
        QJsonArray yArr = json["yData"].toArray();

        QVector<double> x, y;
        for (int i = 0; i < xArr.size(); ++i)
        {
            x << xArr[i].toDouble();
            y << yArr[i].toDouble();
        }

        plot->graph(0)->setData(x, y);
        plot->xAxis->setLabel("X Axis");
        plot->yAxis->setLabel("Y Axis");
        plot->rescaleAxes();
        plot->replot();
        return plot;
    }

    // -------- BAR CHART --------
    else if (type == "bar")
    {
        QCustomPlot* plot = new QCustomPlot(parent);
        QCPBars* bars = new QCPBars(plot->xAxis, plot->yAxis);

        QJsonArray xArr = json["xData"].toArray();
        QJsonArray yArr = json["yData"].toArray();

        QVector<double> x, y;
        for (int i = 0; i < xArr.size(); ++i)
        {
            x << xArr[i].toDouble();
            y << yArr[i].toDouble();
        }

        bars->setData(x, y);
        plot->xAxis->setLabel("X Axis");
        plot->yAxis->setLabel("Y Axis");
        plot->rescaleAxes();
        plot->replot();
        return plot;
    }

    return nullptr;
}
