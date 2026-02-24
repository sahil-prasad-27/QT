#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

using json = nlohmann::json;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize QCustomPlot and place it in the widget
    customPlot = new QCustomPlot(this);
    customPlot->setParent(ui->widgetChart);

    // Fill widgetChart
    QVBoxLayout *layout = new QVBoxLayout(ui->widgetChart);
    layout->addWidget(customPlot);
    ui->widgetChart->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupBarChart(const json &jsonData)
{
    // Example: JSON format
    // [{"label":"A","value":5},{"label":"B","value":8},{"label":"C","value":3}]

    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> data;

    int i = 1;
    for (auto &item : jsonData)
    {
        ticks.push_back(i);
        labels.push_back(QString::fromStdString(item["label"]));
        data.push_back(item["value"]);
        i++;
    }

    customPlot->clearPlottables();
    customPlot->clearItems();

    QCPBars *bars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(bars);
    bars->setWidth(0.6);
    bars->setData(ticks, data);

    // Configure axes
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setRange(0, ticks.size() + 1);

    customPlot->yAxis->setRange(0, *std::max_element(data.begin(), data.end()) * 1.2);

    customPlot->replot();
}

void MainWindow::on_btnLoadData_clicked()
{
    QFile file(":/data.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "Error", "Cannot open data.json");
        return;
    }

    QByteArray rawData = file.readAll();
    file.close();

    try {
        json jsonData = json::parse(rawData);
        setupBarChart(jsonData);
    } catch (json::parse_error &e) {
        QMessageBox::critical(this, "Error", "Invalid JSON format");
        qDebug() << e.what();
    }
}
