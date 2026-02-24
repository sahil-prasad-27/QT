#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphFactory.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnBar, &QPushButton::clicked, this, &MainWindow::on_btnBar_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBar_clicked()
{
    GraphCustomPlot* barGraph = GraphFactory::getQCustomPlot(GraphFactory::BarGraph);
    if (!barGraph) return;

    // Ensure graphWidget has a layout
    QLayout* layout = ui->graphWidget->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->graphWidget);
        ui->graphWidget->setLayout(layout);
    }

    // Clear old widgets
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->setParent(nullptr);
            delete item->widget();
        }
        delete item;
    }

    layout->addWidget(barGraph);

    QList<QPair<QString, double>> graphData;

    QFile file(":/data.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray rawData = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(rawData);
        if (doc.isObject()) {
            QJsonObject rootObj = doc.object();

            // Access BarChart -> Live -> Data
            if (rootObj.contains("BarChart")) {
                QJsonObject barObj = rootObj["BarChart"].toObject();
                if (barObj.contains("Live")) {
                    QJsonObject liveObj = barObj["Live"].toObject();
                    if (liveObj.contains("Data")) {
                        QJsonObject dataObj = liveObj["Data"].toObject();

                        for (auto it = dataObj.begin(); it != dataObj.end(); ++it) {
                            QString valveNumber = it.key();
                            double value = it.value().toDouble();
                            graphData.append(qMakePair(valveNumber, value));
                        }
                    }
                }
            }
        }
    } else {
        qWarning() << "Could not open data.json. Using default data.";

        graphData << qMakePair(QString("0"), 40000)
                  << qMakePair(QString("1"), 47000)
                  << qMakePair(QString("10"), 96000)
                  << qMakePair(QString("11"), 102000);
    }

    barGraph->updateData(graphData);
}


void MainWindow::on_btnLine_clicked()
{
    // Get a LineGraph from the factory
    GraphCustomPlot* lineGraph = GraphFactory::getQCustomPlot(GraphFactory::LineGraph);
    if (!lineGraph)
        return;

    // Ensure graphWidget has a layout
    QLayout* layout = ui->graphWidget->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->graphWidget);
        ui->graphWidget->setLayout(layout);
    }

    // Clear old graph
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget())
            delete item->widget();
        delete item;
    }

    layout->addWidget(lineGraph);

    QList<QPair<QString, double>> graphData;

    QFile file(":/data.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray rawData = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(rawData);
        if (doc.isObject()) {
            QJsonObject rootObj = doc.object();

            // Access LineChart -> Live -> Data
            if (rootObj.contains("LineChart")) {
                QJsonObject lineObj = rootObj["LineChart"].toObject();
                if (lineObj.contains("Live")) {
                    QJsonObject liveObj = lineObj["Live"].toObject();
                    if (liveObj.contains("Data")) {
                        QJsonArray dataArr = liveObj["Data"].toArray();

                        for (const QJsonValue& val : dataArr) {
                            if (val.isObject()) {
                                QJsonObject dataPoint = val.toObject();
                                QString timestamp = dataPoint["TimeStamp"].toString();
                                double airPressure = dataPoint["Air Pressure"].toDouble();
                                graphData.append(qMakePair(timestamp, airPressure));
                            }
                        }
                    }
                }
            }
        }
    } else {
        qWarning() << "Could not open data.json. Using default data.";

        // Default data if file not found
        graphData << qMakePair(QString("2026-02-11T10:00:00Z"), 100.5)
                  << qMakePair(QString("2026-02-11T11:00:00Z"), 101.0)
                  << qMakePair(QString("2026-02-11T12:00:00Z"), 100.8);
    }

    // Update the line graph
    lineGraph->updateData(graphData);
}




void MainWindow::on_btnPie_clicked()
{
    GraphChartView* pieGraph = GraphFactory::getQChartView(GraphFactory::PieGraph);
    if (!pieGraph) return;

    // Ensure layout
    QLayout* layout = ui->graphWidget->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->graphWidget);
        ui->graphWidget->setLayout(layout);
    }

    // Clear old chart
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) item->widget()->setParent(nullptr);
        delete item;
    }
    layout->addWidget(pieGraph);

    QList<QPair<QString,double>> graphData;

    // Load JSON
    QFile file(":/data.json");
    QJsonObject liveObj;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();
        if (doc.isObject()) {
            QJsonObject rootObj = doc.object();
            if (rootObj.contains("PieChart")) {
                QJsonObject pieObj = rootObj["PieChart"].toObject();
                if (pieObj.contains("Live")) {
                    liveObj = pieObj["Live"].toObject();
                }
            }
        }
    }

    // Fallback default
    if (liveObj.isEmpty()) {
        liveObj["Fired Objects"] = QJsonObject{{"count", 1}};
        liveObj["Non Fired Objects"] = QJsonObject{{"count", 1}};
    }

    // Build graphData
    for (auto it = liveObj.begin(); it != liveObj.end(); ++it) {
        QString key = it.key();
        QJsonValue value = it.value();
        double sliceValue = 0;
        QString hoverText;

        if (value.isObject()) {
            QJsonObject obj = value.toObject();

            // Sum all numeric values inside object
            for (auto innerIt = obj.begin(); innerIt != obj.end(); ++innerIt) {
                sliceValue += innerIt.value().toDouble();
            }

            // Build hover text
            QStringList details;
            for (auto innerIt = obj.begin(); innerIt != obj.end(); ++innerIt)
                details << innerIt.key() + ": " + QString::number(innerIt.value().toDouble());
            hoverText = details.join("\n");
        } else {
            sliceValue = value.toDouble();
            hoverText = QString::number(sliceValue);
        }

        // Slice label = Fired / Non Fired
        QString sliceLabel;
        if (key == "Fired Objects")
            sliceLabel = "Fired";
        else if (key == "Non Fired Objects")
            sliceLabel = "Non Fired";
        else
            sliceLabel = key;

        // Combine label + hover if needed (tooltip)
        QString finalLabel = sliceLabel + "\n" + hoverText;

        graphData.append(qMakePair(finalLabel, sliceValue));
    }

    pieGraph->updateData(graphData);
    pieGraph->setGraphTitle("Live Fired Objects Pie Chart");
}
void MainWindow::on_pushButton_clicked()
{
    close();
}
