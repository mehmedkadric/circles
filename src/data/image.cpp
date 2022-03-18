#include "image.h"

cv::Mat Image::getImage() const
{
    return image;
}

Image::Image(QString path)
{
    this->image = cv::imread(path.toStdString());
}
