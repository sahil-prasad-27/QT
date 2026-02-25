#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QThread>
#include "worker.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startCounting();
    void updateProgress(int value);
    void countingFinished();

private:
    QPushButton *startButton;
    QLabel *label;
    QThread *thread;
    Worker *worker;
};

#endif // MAINWINDOW_H
