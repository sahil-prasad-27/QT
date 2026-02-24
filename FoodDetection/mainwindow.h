#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>
#include <opencv2/opencv.hpp>
#include "yolo_detector.h"

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
    void on_startBtn_clicked();     // Start camera
    void on_stopBtn_clicked();      // Stop camera
    void on_exitBtn_clicked();      // Close application
    void on_browseBtn_clicked();    // Browse folder (optional)
    void processFrame();            // Process each frame
    void on_reportBtn_clicked();    // Generate report

private:
    Ui::MainWindow *ui;
    cv::VideoCapture cap;                   // Video capture
    YoloDetector detector;                  // YOLO detector
    cv::Mat currentFrame;                   // Current camera frame
    std::vector<Detection> lastDetections; // Detections in last frame

    QTimer *timer;           // Timer for processing frames
    QElapsedTimer fpsTimer;  // FPS timer
    int frameCount;          // Frame counter for FPS

    // Rolling session storage (max 50 frames)
    std::vector<cv::Mat> sessionFrames;
    std::vector<std::vector<Detection>> sessionDetections;
};

#endif // MAINWINDOW_H
