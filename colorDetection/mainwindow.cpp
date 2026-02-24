#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <fstream>
#include <algorithm>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Paths to YOLOv4-tiny files
    std::string cfg_path = "/home/sahil-prasad/Documents/darknet/cfg/yolov4-tiny.cfg";
    std::string weights_path = "/home/sahil-prasad/Documents/darknet/yolov4-tiny.weights";
    std::string names_path = "/home/sahil-prasad/Documents/darknet/data/coco.names";

    // Load class names
    std::ifstream file(names_path);
    std::string line;
    while (std::getline(file, line)) class_names.push_back(line);

    // Open webcam
    cap.open(0);
    if (!cap.isOpened()) {
        ui->videoLabel->setText("Cannot open webcam!\nCheck /dev/video0 permissions");
        return;
    }

    // Load YOLOv4-tiny network
    net = cv::dnn::readNet(weights_path, cfg_path);
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

    // Timer for live frame update
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateFrame);
    timer->start(30);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Robust color detection
std::string MainWindow::detectColor(const cv::Mat &roi) {
    if (roi.empty()) return "Unknown";

    cv::Mat hsv;
    cv::cvtColor(roi, hsv, cv::COLOR_BGR2HSV);

    struct ColorRange { int h_min, h_max; std::string name; };
    std::vector<ColorRange> colors = {
        {0, 10, "Red"}, {11, 25, "Orange"}, {26, 34, "Yellow"},
        {35, 85, "Green"}, {86, 125, "Blue"}, {126, 160, "Purple"}
    };

    std::vector<int> counts(colors.size(), 0);

    for (int y = 0; y < hsv.rows; ++y) {
        for (int x = 0; x < hsv.cols; ++x) {
            cv::Vec3b px = hsv.at<cv::Vec3b>(y, x);
            int h = px[0], s = px[1], v = px[2];

            if (v < 50) return "Black";
            if (s < 50) return "White";

            for (int i = 0; i < colors.size(); i++) {
                if (h >= colors[i].h_min && h <= colors[i].h_max) counts[i]++;
            }
        }
    }

    int max_idx = std::distance(counts.begin(), std::max_element(counts.begin(), counts.end()));
    return colors[max_idx].name;
}

void MainWindow::updateFrame() {
    if (!cap.isOpened()) return;

    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) return;

    // Resize for faster detection
    cv::Mat resized;
    cv::resize(frame, resized, cv::Size(320, 320));

    cv::Mat blob = cv::dnn::blobFromImage(resized, 1/255.0, cv::Size(320,320), cv::Scalar(), true, false);
    net.setInput(blob);

    std::vector<cv::Mat> outputs;
    net.forward(outputs, net.getUnconnectedOutLayersNames());

    for (auto &output : outputs) {
        for (int i = 0; i < output.rows; i++) {
            float confidence = output.at<float>(i, 4);
            if (confidence > 0.5) {
                int x = static_cast<int>(output.at<float>(i,0) * frame.cols);
                int y = static_cast<int>(output.at<float>(i,1) * frame.rows);
                int w = static_cast<int>(output.at<float>(i,2) * frame.cols);
                int h = static_cast<int>(output.at<float>(i,3) * frame.rows);

                cv::Rect box(x-w/2, y-h/2, w, h);
                box &= cv::Rect(0,0,frame.cols, frame.rows);

                cv::rectangle(frame, box, cv::Scalar(0,255,0), 2);

                cv::Mat roi = frame(box);
                std::string color = detectColor(roi);

                int classId = 0;
                float maxProb = 0;
                for (int j = 0; j < class_names.size(); j++) {
                    float prob = output.at<float>(i, 5+j);
                    if (prob > maxProb) { maxProb = prob; classId = j; }
                }

                std::string label = class_names[classId] + " " + color;
                cv::putText(frame, label, cv::Point(box.x, box.y-10),
                            cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(0,255,255), 2);
            }
        }
    }

    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    QImage img((uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    ui->videoLabel->setPixmap(QPixmap::fromImage(img));
}
