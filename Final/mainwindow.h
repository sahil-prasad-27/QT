#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_barButton_clicked();

    void on_lineButton_clicked();

    void on_pieButton_clicked();

    void on_close_1_clicked();

private:
    Ui::MainWindow *ui;
    void showChart(Chart *factory);
};

#endif
