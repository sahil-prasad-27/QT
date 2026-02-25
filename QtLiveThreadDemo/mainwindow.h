#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include "workerthread.h"

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
    void onStartClicked();
    void onPauseClicked();
    void onResumeClicked();

    void updateUI(const QString &text, const QPixmap &icon);
    void showLoading();
    void hideLoading();

private:
    Ui::MainWindow *ui;
    WorkerThread *worker;
    QMovie *loadingMovie;
};

#endif
