#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QScrollBar>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      detector(CFG_PATH, WEIGHTS_PATH, NAMES_PATH),
      frameCount(0)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::processFrame);

    // Ensure report button is connected correctly
    connect(ui->reportBtn, &QPushButton::clicked,
            this, &MainWindow::on_reportBtn_clicked);

    ui->fpsLabel->setText("FPS: 0");
    ui->statusLabel->setText("Status: Idle");

    // Optional: make report look like Kafka console
    if (ui->reportTextEdit) {
        ui->reportTextEdit->setReadOnly(true);
        ui->reportTextEdit->setStyleSheet(
            "background-color:black; color:lime; font-family:Courier; font-size:11pt;"
        );
    }
}

MainWindow::~MainWindow()
{
    if (cap.isOpened()) cap.release();
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    if (!cap.open(0)) {
        QMessageBox::critical(this, "Error", "Cannot open camera");
        return;
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    frameCount = 0;
    fpsTimer.start();

    sessionFrames.clear();
    sessionDetections.clear();

    timer->start(0);
    ui->statusLabel->setText("Status: Detecting...");
}

void MainWindow::on_stopBtn_clicked()
{
    timer->stop();
    if (cap.isOpened()) cap.release();
    ui->statusLabel->setText("Status: Stopped");
}

void MainWindow::on_exitBtn_clicked()
{
    close();
}

void MainWindow::on_browseBtn_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this,
        "Select Folder", "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!folder.isEmpty()) {
        QMessageBox::information(this, "Selected Folder", folder);
    }
}

void MainWindow::processFrame()
{
    if (!cap.read(currentFrame) || currentFrame.empty())
        return;

    cv::Mat frame = currentFrame.clone();

    // Run detection
    lastDetections = detector.detect(frame);

    // Store in memory
    sessionFrames.push_back(frame);
    sessionDetections.push_back(lastDetections);

    // Rolling buffer (max 50)
    const int maxImages = 50;
    if (sessionFrames.size() > maxImages) {
        sessionFrames.erase(sessionFrames.begin());
        sessionDetections.erase(sessionDetections.begin());
    }

    // Draw detections
    for (auto &det : lastDetections) {
        cv::Rect safe = det.box & cv::Rect(0,0, frame.cols, frame.rows);
        if (safe.width <= 0 || safe.height <= 0) continue;

        cv::rectangle(frame, safe, cv::Scalar(0,255,0), 2);
        cv::putText(frame, det.label, safe.tl(),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5,
                    cv::Scalar(0,0,255), 2);
    }

    // FPS calculation
    frameCount++;
    if (fpsTimer.elapsed() >= 1000) {
        ui->fpsLabel->setText("FPS: " + QString::number(frameCount));
        frameCount = 0;
        fpsTimer.restart();
    }

    // Convert to RGB
    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    QImage img(frame.data, frame.cols, frame.rows,
               frame.step, QImage::Format_RGB888);

    ui->videoLabel->setPixmap(
        QPixmap::fromImage(img)
        .scaled(ui->videoLabel->size(),
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation));
}

void MainWindow::on_reportBtn_clicked()
{
    if (!ui->reportTextEdit) return; // Safety check

    if (sessionDetections.empty()) {
        ui->reportTextEdit->setPlainText("No detections available.\n");
        return;
    }

    QString report;
    report += "╔════════════════════════════╗\n";
    report += "║      DETECTION REPORT      ║\n";
    report += "╚════════════════════════════╝\n\n";

    QMap<QString,int> objectCount;
    int frameNumber = 1;

    for (const auto &detections : sessionDetections) {
        report += QString("Frame %1:\n").arg(frameNumber++);
        if (detections.empty()) {
            report += "  [No objects detected]\n";
        } else {
            for (auto &det : detections) {
                QString label = QString::fromStdString(det.label);
                report += QString("  >> %1\n").arg(label);
                objectCount[label]++;
            }
        }
        report += "\n";
    }

    report += "╔════════════════════════════╗\n";
    report += "║        SUMMARY             ║\n";
    report += "╚════════════════════════════╝\n";

    for (auto it = objectCount.begin(); it != objectCount.end(); ++it)
        report += QString("  %1 : %2\n").arg(it.key()).arg(it.value());

    // Show in QTextEdit
    ui->reportTextEdit->setPlainText(report);

    // Scroll to bottom like Kafka log
    ui->reportTextEdit->verticalScrollBar()->setValue(
        ui->reportTextEdit->verticalScrollBar()->maximum()
    );
}
