#ifndef PIECHARTFACTORY_H
#define PIECHARTFACTORY_H

#include "chart.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class PieChart : public Chart
{
protected:
    void createSeries(QChart *chart, const QJsonObject &json) override
    {
        QPieSeries *series = new QPieSeries();

        for (auto v : json["pieSeries"].toArray()) {
            QJsonObject obj = v.toObject();
            series->append(obj["name"].toString(), obj["value"].toDouble());
        }

        chart->addSeries(series);
        chart->setTitle("Pie Chart");
    }
};


#endif
