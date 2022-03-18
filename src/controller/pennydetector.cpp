#include "pennydetector.h"
#include "cmath"
#include "QDebug"
#include "backgroundremover.h"


cv::Mat PennyDetector::preprocessImage(cv::Mat img)
{
    /* Make image smooth, remove predefined (light) background and perform thresholding */
    cv::Mat out_img, out_img_thresholded;
    cv::blur(img, out_img, cv::Size(3, 3), cv::Point(-1, -1));
    BackgroundRemover backgroundRemover(out_img);
    out_img = backgroundRemover.remove();
    cv::threshold(out_img, out_img_thresholded, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    return out_img_thresholded;
}

QImage PennyDetector::getImageLabel()
{
    cv::Mat rgb, out;
    cv::resize(this->image, out, cv::Size(300, 400), cv::INTER_LINEAR);
    cv::cvtColor(out, rgb, cv::COLOR_BGR2RGB);
    return QImage((uchar*) rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);
}

std::vector<std::vector<cv::Point> > PennyDetector::findContours()
{
    cv::Mat src_gray, canny_output;
    cv::Mat src_img = this->image.clone();

    /* Perform preprocessing */
    cv::Mat src_gray_thresholded = preprocessImage(src_img);
    /* Perform morphological filtering */
    cv::dilate(src_gray_thresholded, src_gray_thresholded, cv::Mat::ones(5, 5, CV_8U), cv::Point(-1, -1), 4);
    cv::erode(src_gray_thresholded, src_gray_thresholded, cv::Mat::ones(3, 3, CV_8U));

    /* Edge detection in filtered image */
    cv::Canny( src_gray_thresholded, canny_output, 100, 200 );

    /* Countour find method */
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours( canny_output, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE );

    return contours;
}

std::vector<std::vector<cv::Point>> PennyDetector::filterContours(std::vector<std::vector<cv::Point>> contours)
{
    /* Filter out contours with cilcularity lower than predefined threshold */
    std::vector<std::vector<cv::Point>> filtered_contours;
    for( size_t i = 0; i< contours.size(); i++ ) {
        double contourArea = cv::contourArea(contours[i]);
        double contourPerimeter = cv::arcLength(contours[i], true);
        double circularity = (4.0 * M_PI * contourArea) / (contourPerimeter * contourPerimeter);
        qDebug() << "Area:" << contourArea <<"; Perimeter:" << contourPerimeter << "; Circularity: " << circularity;
        if(circularity > this->threshold) {
            filtered_contours.push_back(contours[i]);
        }
    }
    return filtered_contours;
}

PennyDetector::PennyDetector(cv::Mat image)
{
    this->image = image;
}

QString PennyDetector::detect()
{
    std::vector<std::vector<cv::Point> > detected_contours = filterContours(findContours());
    /* Create green circles around detected pennies */
    cv::Mat drawing = cv::Mat::zeros( this->image.size(), CV_8UC3 );

    for( size_t i = 0; i< detected_contours.size(); i++ ) {
        cv::Scalar color = cv::Scalar( 0, 255, 0 );
        cv::drawContours( drawing, detected_contours, (int)i, color, 5, cv::LINE_8);
    }
    QString status = "Number of detected pennies is " + QString::number(detected_contours.size()) + ".";
    this->image = this->image + drawing;
    return status;
}
