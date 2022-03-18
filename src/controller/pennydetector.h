#ifndef PENNYDETECTOR_H
#define PENNYDETECTOR_H

#include "opencv2/opencv.hpp"
#include "iostream"
#include "QString"
#include "QImage"

class PennyDetector
{
private:
    cv::Mat image;
    double threshold = 0.84;
    std::vector<std::vector<cv::Point>> findContours();
    std::vector<std::vector<cv::Point>> filterContours(std::vector<std::vector<cv::Point>>);
    cv::Mat preprocessImage(cv::Mat);
public:
    PennyDetector(cv::Mat);
    QString detect();
    QImage getImageLabel();
};

#endif // PENNYDETECTOR_H
