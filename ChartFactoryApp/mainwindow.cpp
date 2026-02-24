#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chartfactory.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QScrollArea>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadChartsFromJson(":/data.json");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadChartsFromJson(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        return;

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray chartsArr = doc.object()["charts"].toArray();

    QVBoxLayout* layout = new QVBoxLayout();
    QWidget* container = new QWidget();
    container->setLayout(layout);

    for (const QJsonValue& v : chartsArr)
    {
        QJsonObject chartObj = v.toObject();
        QWidget* chartWidget = ChartFactory::createChart(chartObj, this);
        if(chartWidget)
            layout->addWidget(chartWidget);
    }

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(container);

    setCentralWidget(scrollArea);
}
