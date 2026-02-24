#ifndef CHARTFACTORY_H
#define CHARTFACTORY_H

#include <QWidget>
#include <QJsonObject>

class ChartFactory
{
public:
    static QWidget* createChart(const QJsonObject& json, QWidget* parent = nullptr);
};

#endif // CHARTFACTORY_H
