#include "controller.h"
#include "src/controller/pennydetector.h"
#include "src/data/image.h"
#include "QDebug"

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::calculate(QString path, int method) {
    Image image(path);
    if(method == 0) {
        PennyDetector pennyDetector(image.getImage());
        QString status = pennyDetector.detect();
        emit(updateStatusLabel(status));
        emit(updateImageLabel(pennyDetector.getImageLabel()));

    } else if (method == 1) {
        QString status = "Selected method is not implemented.";
        emit(updateStatusLabel(status));
    }

}
