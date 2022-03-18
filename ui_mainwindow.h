/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *imageLabel;
    QComboBox *methodComboBox;
    QLabel *chooseMethodLabel;
    QPushButton *runPushButton;
    QPushButton *chooseImagePushButton;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLabel *statusLabel;
    QLabel *numberOfPenniesLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));

        gridLayout->addWidget(imageLabel, 3, 0, 1, 3, Qt::AlignHCenter);

        methodComboBox = new QComboBox(centralwidget);
        methodComboBox->addItem(QString());
        methodComboBox->addItem(QString());
        methodComboBox->setObjectName(QString::fromUtf8("methodComboBox"));

        gridLayout->addWidget(methodComboBox, 2, 0, 1, 3, Qt::AlignHCenter);

        chooseMethodLabel = new QLabel(centralwidget);
        chooseMethodLabel->setObjectName(QString::fromUtf8("chooseMethodLabel"));
        chooseMethodLabel->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));

        gridLayout->addWidget(chooseMethodLabel, 1, 0, 1, 3, Qt::AlignHCenter);

        runPushButton = new QPushButton(centralwidget);
        runPushButton->setObjectName(QString::fromUtf8("runPushButton"));
        runPushButton->setEnabled(false);

        gridLayout->addWidget(runPushButton, 7, 2, 1, 1);

        chooseImagePushButton = new QPushButton(centralwidget);
        chooseImagePushButton->setObjectName(QString::fromUtf8("chooseImagePushButton"));

        gridLayout->addWidget(chooseImagePushButton, 7, 0, 1, 1);

        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("font: 36pt \".AppleSystemUIFont\";"));

        gridLayout->addWidget(titleLabel, 0, 0, 1, 3, Qt::AlignHCenter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 3);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        gridLayout->addWidget(statusLabel, 6, 0, 1, 3, Qt::AlignHCenter);

        numberOfPenniesLabel = new QLabel(centralwidget);
        numberOfPenniesLabel->setObjectName(QString::fromUtf8("numberOfPenniesLabel"));
        numberOfPenniesLabel->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));

        gridLayout->addWidget(numberOfPenniesLabel, 5, 0, 1, 3, Qt::AlignHCenter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        imageLabel->setText(QString());
        methodComboBox->setItemText(0, QApplication::translate("MainWindow", "Circularity Detection", nullptr));
        methodComboBox->setItemText(1, QApplication::translate("MainWindow", "Hough Method", nullptr));

        chooseMethodLabel->setText(QApplication::translate("MainWindow", "Choose method", nullptr));
        runPushButton->setText(QApplication::translate("MainWindow", "Run", nullptr));
        chooseImagePushButton->setText(QApplication::translate("MainWindow", "Choose Image", nullptr));
        titleLabel->setText(QApplication::translate("MainWindow", "PENNY CALCULATOR", nullptr));
        statusLabel->setText(QString());
        numberOfPenniesLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
