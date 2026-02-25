#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), thread(nullptr), worker(nullptr)
{
    resize(600, 350);

    startButton = new QPushButton("Start Counting", this);
    startButton->setGeometry(80, 30, 140, 40);

    label = new QLabel("Progress: 0", this);
    label->setGeometry(100, 90, 100, 30);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startCounting);
}

MainWindow::~MainWindow()
{
    if (thread && thread->isRunning()) {
        thread->quit();
        thread->wait();
    }
}

void MainWindow::startCounting()
{
    startButton->setEnabled(false);

    worker = new Worker();
    thread = new QThread();

    worker->moveToThread(thread);

    connect(thread, &QThread::started, worker, &Worker::doWork);
    connect(worker, &Worker::progress, this, &MainWindow::updateProgress);
    connect(worker, &Worker::finished, this, &MainWindow::countingFinished);
    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void MainWindow::updateProgress(int value)
{
    label->setText(QString("Progress: %1").arg(value));
}

void MainWindow::countingFinished()
{
    startButton->setEnabled(true);
    label->setText("Finished!");
}
