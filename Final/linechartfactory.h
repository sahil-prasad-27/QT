#ifndef LINECHARTFACTORY_H
#define LINECHARTFACTORY_H

#include "chart.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class LineChart : public Chart
{
protected:
    void createSeries(QChart *chart, const QJsonObject &json) override
    {
        QLineSeries *series = new QLineSeries();
        series->setName("Line Chart");

        QJsonArray values = json["lineSeries"].toArray().first()
                                .toObject()["values"].toArray();

        for (int i = 0; i < values.size(); ++i) {
            series->append(i, values[i].toDouble());
        }

        chart->addSeries(series);
        chart->setTitle("Line Chart");
    }
};

#endif
