#ifndef IMAGE_SAVER_H
#define IMAGE_SAVER_H

#include <opencv2/opencv.hpp>
#include "yolo_detector.h"
#include <deque>
#include <QString>

class ImageSaver {
public:
    static void saveAllRolling(const cv::Mat& rawFrame,
                               const std::vector<Detection>& detections,
                               int maxImages = 50);

private:
    static std::deque<QString> savedFiles; // tracks segment filenames
};

#endif
