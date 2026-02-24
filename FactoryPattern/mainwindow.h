#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_btnBar_clicked();

    void on_btnLine_clicked();

    void on_btnPie_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif
