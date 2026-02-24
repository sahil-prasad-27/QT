#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupChartFromJson(":/data.json");  // replace with actual path
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Load JSON from file
QJsonObject MainWindow::loadJson(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open JSON file:" << filePath;
        return {};
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        qWarning() << "JSON is not an object!";
        return {};
    }

    return doc.object();
}

// Create chart from JSON
void MainWindow::setupChartFromJson(const QString &jsonPath)
{
    QJsonObject json = loadJson(jsonPath);
    if (json.isEmpty()) return;

    QStringList categories;
    QJsonArray catArray = json["categories"].toArray();
    for (const QJsonValue &val : catArray)
        categories.append(val.toString());

    QChart *chart = new QChart();
    chart->setTitle("Bar + Line Chart from JSON");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // --- Bar Series ---
    QBarSeries *barSeries = new QBarSeries();
    QJsonArray barArray = json["barSeries"].toArray();

    for (const QJsonValue &val : barArray) {
        QJsonObject obj = val.toObject();
        QString name = obj["name"].toString();
        QJsonArray values = obj["values"].toArray();

        QBarSet *barSet = new QBarSet(name);
        for (const QJsonValue &v : values)
            *barSet << v.toDouble();

        barSeries->append(barSet);
    }

    chart->addSeries(barSeries);

    // --- Line Series ---
    QJsonArray lineArray = json["lineSeries"].toArray();
    for (const QJsonValue &val : lineArray) {
        QJsonObject obj = val.toObject();
        QString name = obj["name"].toString();
        QJsonArray values = obj["values"].toArray();

        QLineSeries *line = new QLineSeries();
        line->setName(name);

        for (int i = 0; i < values.size(); ++i) {
            line->append(i, values[i].toDouble()); // x = index, y = value
        }

        chart->addSeries(line);
    }

    // --- Axes ---
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Month");

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Value");

    // Attach axes to bar series
    barSeries->attachAxis(axisX);
    barSeries->attachAxis(axisY);

    // Attach axes to line series
    QLineSeries *lineSeries = nullptr;
    foreach (QAbstractSeries *s, chart->series()) {
        if (s->type() == QAbstractSeries::SeriesTypeLine) {
            lineSeries = qobject_cast<QLineSeries *>(s);
            if (lineSeries) {
                lineSeries->attachAxis(axisX);
                lineSeries->attachAxis(axisY);
            }
        }
    }

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // --- Chart View ---
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(ui->horizontalFrame);
    layout->addWidget(chartView);
}

