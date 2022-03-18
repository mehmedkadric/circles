#include "backgroundremover.h"

#include "QDebug"

BackgroundRemover::BackgroundRemover(cv::Mat image)
{
    if(image.channels() != 3) {
        this->image = cv::Mat::zeros(image.size(), CV_8UC3);
        qDebug() << "Not 3-channel image!";
    } else {
        this->image = image;
    }
}

cv::Mat BackgroundRemover::remove()
{
    cv::Mat hsvImage, out;
    cv::cvtColor(this->image, hsvImage, cv::COLOR_BGR2HSV);

    cv::inRange(hsvImage, cv::Scalar(0, 70, 0), cv::Scalar(255, 255, 255), out);

    return out;

}
