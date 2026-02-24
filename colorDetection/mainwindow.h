#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateFrame();

private:
    Ui::MainWindow *ui;
    cv::VideoCapture cap;
    cv::dnn::Net net;
    QTimer *timer;
    std::vector<std::string> class_names;

    std::string detectColor(const cv::Mat &roi);
};

#endif // MAINWINDOW_H
