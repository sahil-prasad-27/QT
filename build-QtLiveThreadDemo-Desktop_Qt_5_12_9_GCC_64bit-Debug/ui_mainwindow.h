/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *dataLabel;
    QLabel *iconLabel;
    QLabel *loadingLabel;
    QPushButton *startButton;
    QPushButton *resumeButton;
    QPushButton *pauseButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        dataLabel = new QLabel(centralwidget);
        dataLabel->setObjectName(QString::fromUtf8("dataLabel"));
        dataLabel->setGeometry(QRect(10, 40, 231, 191));
        dataLabel->setAlignment(Qt::AlignCenter);
        iconLabel = new QLabel(centralwidget);
        iconLabel->setObjectName(QString::fromUtf8("iconLabel"));
        iconLabel->setGeometry(QRect(280, 40, 311, 161));
        iconLabel->setAlignment(Qt::AlignCenter);
        loadingLabel = new QLabel(centralwidget);
        loadingLabel->setObjectName(QString::fromUtf8("loadingLabel"));
        loadingLabel->setGeometry(QRect(600, 50, 161, 141));
        loadingLabel->setAlignment(Qt::AlignCenter);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(80, 350, 89, 25));
        resumeButton = new QPushButton(centralwidget);
        resumeButton->setObjectName(QString::fromUtf8("resumeButton"));
        resumeButton->setGeometry(QRect(660, 340, 89, 25));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(390, 340, 89, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        dataLabel->setText(QApplication::translate("MainWindow", "Data will appear here", nullptr));
        iconLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        loadingLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        resumeButton->setText(QApplication::translate("MainWindow", "Resume", nullptr));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
