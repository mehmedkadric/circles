#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "opencv2/opencv.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&controller, &Controller::updateStatusLabel, this, &MainWindow::updateStatusLabel);
    connect(&controller, &Controller::updateImageLabel, this, &MainWindow::updateImageLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_chooseImagePushButton_clicked()
{
    try {
        QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        "/Users/mehmed/Desktop/",
                                                        tr("Images (*.png *.PNG *.jpg *.JPG *.jpeg *.JPEG)"));

        this->path = path;

        /* Prepare image for preview */
        cv::Mat image = cv::imread(this->path.toStdString());
        cv::resize(image, image, cv::Size(300, 400), cv::INTER_LINEAR);
        cv::Mat rgb;
        cv::cvtColor(image, rgb, cv::COLOR_BGR2RGB);
        QImage qimage = QImage((uchar*) rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);

        /* Setup labels */
        ui->imageLabel->setPixmap(QPixmap::fromImage(qimage));
        ui->statusLabel->setText(path);
        ui->runPushButton->setEnabled(true);
    } catch (...) {
        ui->statusLabel->setText("");
    }

}

void MainWindow::on_runPushButton_clicked()
{
    controller.calculate(this->path, ui->methodComboBox->currentIndex());
}

void MainWindow::updateStatusLabel(QString text) {
    ui->numberOfPenniesLabel->setText(text);
}

void MainWindow::updateImageLabel(QImage image) {
    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
}
