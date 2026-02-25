#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      worker(nullptr)
{
    ui->setupUi(this);

    loadingMovie = new QMovie(":/images/loading.gif");
    ui->loadingLabel->setMovie(loadingMovie);
    ui->loadingLabel->setVisible(false);

    connect(ui->startButton, &QPushButton::clicked,
            this, &MainWindow::onStartClicked);

    connect(ui->pauseButton, &QPushButton::clicked,
            this, &MainWindow::onPauseClicked);

    connect(ui->resumeButton, &QPushButton::clicked,
            this, &MainWindow::onResumeClicked);
}

MainWindow::~MainWindow()
{
    if (worker)
    {
        worker->stop();
        worker->wait();
        delete worker;
    }
    delete ui;
}

void MainWindow::onStartClicked()
{
    if (!worker)
    {
        worker = new WorkerThread();

        connect(worker, &WorkerThread::dataReady,
                this, &MainWindow::updateUI);

        connect(worker, &WorkerThread::fetchingStarted,
                this, &MainWindow::showLoading);

        connect(worker, &WorkerThread::fetchingFinished,
                this, &MainWindow::hideLoading);

        worker->start();
    }
}

void MainWindow::onPauseClicked()
{
    if (worker) worker->pause();
}

void MainWindow::onResumeClicked()
{
    if (worker) worker->resume();
}

void MainWindow::updateUI(const QString &text, const QPixmap &icon)
{
    ui->dataLabel->setText(text);

    if (!icon.isNull())
        ui->iconLabel->setPixmap(icon.scaled(100,100,Qt::KeepAspectRatio));
    else
        ui->iconLabel->clear();
}

void MainWindow::showLoading()
{
    ui->loadingLabel->setVisible(true);
    loadingMovie->start();
}

void MainWindow::hideLoading()
{
    loadingMovie->stop();
    ui->loadingLabel->setVisible(false);
}
