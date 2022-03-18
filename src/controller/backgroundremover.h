#ifndef BACKGROUNDREMOVER_H
#define BACKGROUNDREMOVER_H

#include "opencv2/opencv.hpp"

class BackgroundRemover
{
private:
    cv::Mat image;
public:
    BackgroundRemover(cv::Mat);
    cv::Mat remove();
};

#endif // BACKGROUNDREMOVER_H
