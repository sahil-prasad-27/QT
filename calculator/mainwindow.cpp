#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DateTimer = new QTimer;
    connect(DateTimer, SIGNAL(timeout()), this, SLOT(Date_Time_Display_Slot()));
    DateTimer->setInterval(1000);
    DateTimer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Date_Time_Display_Slot()
{
    QString DateAndTime = QDateTime::currentDateTime().toString("dd:MM:yyyy HH:mm:ss");
    ui->lcdNumber->display(DateAndTime);
}

