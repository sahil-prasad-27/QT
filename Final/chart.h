#ifndef CHARTFACTORY_H
#define CHARTFACTORY_H

#include <QtCharts>
#include <QString>

class Chart
{
public:
    virtual ~Chart() {}

    QChartView* createChart(const QString &jsonPath)
    {
        QJsonObject json = loadJson(jsonPath);
        if (json.isEmpty()) return nullptr;

        QChart *chart = new QChart();
        chart->setAnimationOptions(QChart::SeriesAnimations);

        createSeries(chart, json);
        setupAxes(chart, json);

        QChartView *view = new QChartView(chart);
        view->setRenderHint(QPainter::Antialiasing);
        return view;
    }

protected:

    virtual void createSeries(QChart *chart, const QJsonObject &json) = 0;

    void setupAxes(QChart *chart, const QJsonObject &json)
    {
        QStringList categories;
        for (auto v : json["categories"].toArray())
            categories << v.toString();

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);

        QValueAxis *axisY = new QValueAxis();

        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);

        for (auto s : chart->series()) {
            s->attachAxis(axisX);
            s->attachAxis(axisY);
        }
    }

    QJsonObject loadJson(const QString &path)
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly)) return {};
        return QJsonDocument::fromJson(file.readAll()).object();
    }
};


#endif
