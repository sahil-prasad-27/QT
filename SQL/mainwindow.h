#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QThread>
#include "dbworker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;

    void connectToDatabase();
    void createTable();
    void insertUser(const QString &name, int age);
    void readUsers();
    void runWorkerThread();

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonUpdate_clicked();
};

#endif // MAINWINDOW_H
