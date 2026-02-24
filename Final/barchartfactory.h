#ifndef BARCHARTFACTORY_H
#define BARCHARTFACTORY_H

#include "chart.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class BarChart : public Chart
{
protected:
    void createSeries(QChart *chart, const QJsonObject &json) override
    {
        QBarSeries *series = new QBarSeries();

        for (auto v : json["barSeries"].toArray()) {
            QJsonObject obj = v.toObject();
            QBarSet *set = new QBarSet(obj["name"].toString());
            for (auto val : obj["values"].toArray())
                *set << val.toDouble();
            series->append(set);
        }

        chart->addSeries(series);
        chart->setTitle("Bar Chart");
    }
};


#endif
