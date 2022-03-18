#ifndef IMAGE_H
#define IMAGE_H

#include "QString"
#include "opencv2/opencv.hpp"

class Image
{
private:
    QString path;
    cv::Mat image;
public:
    Image(QString);
    cv::Mat getImage() const;
};

#endif // IMAGE_H
