// config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <string>

const std::string CFG_PATH = "/home/sahil-prasad/Documents/darknet/cfg/yolov4.cfg";
const std::string WEIGHTS_PATH = "/home/sahil-prasad/Documents/darknet/yolov4.weights";
const std::string NAMES_PATH = "/home/sahil-prasad/Documents/darknet/data/coco.names";

const float CONF_THRESHOLD = 0.5;   // Confidence threshold
const float NMS_THRESHOLD = 0.4;    // Non-maximum suppression threshold

#endif // CONFIG_H
