#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_chooseImagePushButton_clicked();
    void on_runPushButton_clicked();
    void updateStatusLabel(QString);
    void updateImageLabel(QImage);

private:
    Ui::MainWindow *ui;
    QString path;
    Controller controller;
};
#endif // MAINWINDOW_H
