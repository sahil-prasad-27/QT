#ifndef YOLO_DETECTOR_H
#define YOLO_DETECTOR_H

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <set>
#include <string>
#include <vector>

struct Detection {
    cv::Rect box;
    std::string label;
    float confidence;
};

class YoloDetector {
public:
    YoloDetector(const std::string& cfg,
                 const std::string& weights,
                 const std::string& names);

    // Detect objects in frame, but return only food items
    std::vector<Detection> detect(const cv::Mat& frame);

private:
    cv::dnn::Net net;
    std::vector<std::string> classNames;

    // Set of food classes from COCO
    const std::set<std::string> foodClasses = {
        "apple","banana","orange","broccoli","carrot",
        "hot dog","pizza","donut","cake","sandwich"
    };
};

#endif
