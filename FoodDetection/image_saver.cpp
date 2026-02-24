#include "image_saver.h"
#include <QDir>
#include <QFile>
#include <iostream>

std::deque<QString> ImageSaver::savedFiles;

void ImageSaver::saveAllRolling(const cv::Mat& rawFrame,
                                const std::vector<Detection>& detections,
                                int maxImages)
{
    try {
        QDir dir;
        dir.mkpath("output/segments");

        cv::Mat bboxFrame = rawFrame.clone();
        int idx = 0;

        for (const auto& det : detections) {
            cv::Rect safeBox = det.box & cv::Rect(0,0, rawFrame.cols, rawFrame.rows);
            if (safeBox.width <= 0 || safeBox.height <= 0) continue;

            cv::rectangle(bboxFrame, safeBox, cv::Scalar(0,255,0), 2);

            cv::Mat crop = rawFrame(safeBox).clone();
            QString filename = QString("output/segments/segment_%1.png").arg(idx++);

            cv::imwrite(filename.toStdString(), crop);

            // Track saved files
            savedFiles.push_back(filename);
            if (savedFiles.size() > maxImages) {
                QString oldest = savedFiles.front();
                savedFiles.pop_front();
                QFile::remove(oldest);
            }
        }

        cv::imwrite("output/bbox.png", bboxFrame);

    } catch (const cv::Exception& e) {
        std::cerr << "Image Save Error: " << e.what() << std::endl;
    }
}
