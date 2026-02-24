#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Start_clicked()
{
    int val =0;
    while(val <= 100){
        QThread::msleep(100);
        ui->progressBar->setValue(val);
        val += 1;
        qApp->processEvents(QEventLoop::AllEvents);
    }
}
