#include "yolo_detector.h"
#include "config.h"
#include <fstream>
#include <iostream>

YoloDetector::YoloDetector(const std::string& cfg,
                           const std::string& weights,
                           const std::string& names)
{
    try {
        // Load YOLO network
        net = cv::dnn::readNetFromDarknet(cfg, weights);
        net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

        // Load class names
        std::ifstream ifs(names);
        std::string line;
        while (std::getline(ifs, line))
            classNames.push_back(line);

        if (classNames.empty())
            throw std::runtime_error("Class names file is empty");

    } catch (const cv::Exception& e) {
        std::cerr << "YOLO Load Error: " << e.what() << std::endl;
        throw;
    } catch (const std::exception& e) {
        std::cerr << "YOLO Load Error: " << e.what() << std::endl;
        throw;
    }
}

std::vector<Detection> YoloDetector::detect(const cv::Mat& frame)
{
    std::vector<Detection> detections;

    try {
        cv::Mat blob;
        cv::dnn::blobFromImage(frame, blob, 1/255.0,
                               cv::Size(416, 416),
                               cv::Scalar(), true, false);

        net.setInput(blob);

        std::vector<cv::Mat> outputs;
        net.forward(outputs, net.getUnconnectedOutLayersNames());

        std::vector<int> classIds;
        std::vector<float> confidences;
        std::vector<cv::Rect> boxes;

        // Parse network outputs
        for (auto& output : outputs) {
            for (int i = 0; i < output.rows; ++i) {
                float* data = (float*)output.ptr(i);
                float confidence = data[4];

                if (confidence >= CONF_THRESHOLD) {
                    float* scores = data + 5;
                    cv::Mat scoresMat(1, classNames.size(), CV_32FC1, scores);

                    cv::Point classIdPoint;
                    double maxScore;
                    cv::minMaxLoc(scoresMat, 0, &maxScore, 0, &classIdPoint);

                    if (maxScore > CONF_THRESHOLD) {
                        int centerX = (int)(data[0] * frame.cols);
                        int centerY = (int)(data[1] * frame.rows);
                        int width = (int)(data[2] * frame.cols);
                        int height = (int)(data[3] * frame.rows);
                        int left = centerX - width/2;
                        int top = centerY - height/2;

                        boxes.emplace_back(left, top, width, height);
                        classIds.push_back(classIdPoint.x);
                        confidences.push_back((float)maxScore);
                    }
                }
            }
        }

        // Non-maximum suppression
        std::vector<int> indices;
        cv::dnn::NMSBoxes(boxes, confidences,
                          CONF_THRESHOLD,
                          NMS_THRESHOLD,
                          indices);

        // Build final detection list (food-only)
        for (int idx : indices) {
            std::string label = classNames[classIds[idx]];

            // Skip non-food objects
            if (foodClasses.find(label) == foodClasses.end())
                continue;

            Detection det;
            det.box = boxes[idx];
            det.label = label;
            det.confidence = confidences[idx];
            detections.push_back(det);
        }

    } catch (const cv::Exception& e) {
        std::cerr << "Detection Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Detection Error: " << e.what() << std::endl;
    }

    return detections;
}
