#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <nlohmann/json.hpp>

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
    void on_btnLoadData_clicked();

private:
    Ui::MainWindow *ui;
    QCustomPlot *customPlot;

    void setupBarChart(const nlohmann::json &jsonData);
};

#endif // MAINWINDOW_H
