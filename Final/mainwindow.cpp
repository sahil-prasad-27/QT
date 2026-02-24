#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "barchartfactory.h"
#include "linechartfactory.h"
#include <QVBoxLayout>
#include "piechartfactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->barButton, &QPushButton::clicked, this, &MainWindow::on_barButton_clicked);
    connect(ui->lineButton, &QPushButton::clicked, this, &MainWindow::on_lineButton_clicked);
    connect(ui->pieButton, &QPushButton::clicked,
            this, &MainWindow::on_pieButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showChart(Chart *factory)
{
    QLayout *layout = ui->horizontalFrame->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete layout;
    }

    QChartView *chartView = factory->createChart(":/data.json");
    if (!chartView) return;

    QVBoxLayout *vLayout = new QVBoxLayout(ui->horizontalFrame);
    vLayout->addWidget(chartView);
}


void MainWindow::on_barButton_clicked()
{
    BarChart barFactory;
    showChart(&barFactory);
}

void MainWindow::on_lineButton_clicked()
{
    LineChart lineFactory;
    showChart(&lineFactory);
}

void MainWindow::on_pieButton_clicked()
{
    PieChart pieFactory;
    showChart(&pieFactory);
}

void MainWindow::on_close_1_clicked()
{
    close();
}
