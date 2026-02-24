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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QFrame *horizontalFrame;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *barButton;
    QPushButton *pieButton;
    QPushButton *lineButton;
    QPushButton *close_1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 801, 431));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalFrame = new QFrame(widget);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalFrame->setFrameShape(QFrame::StyledPanel);
        horizontalFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(horizontalFrame);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(180, 440, 431, 121));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        barButton = new QPushButton(widget1);
        barButton->setObjectName(QString::fromUtf8("barButton"));

        horizontalLayout->addWidget(barButton);

        pieButton = new QPushButton(widget1);
        pieButton->setObjectName(QString::fromUtf8("pieButton"));

        horizontalLayout->addWidget(pieButton);

        lineButton = new QPushButton(widget1);
        lineButton->setObjectName(QString::fromUtf8("lineButton"));

        horizontalLayout->addWidget(lineButton);

        close_1 = new QPushButton(widget1);
        close_1->setObjectName(QString::fromUtf8("close_1"));

        horizontalLayout->addWidget(close_1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        barButton->setText(QApplication::translate("MainWindow", "Bar Chart", nullptr));
        pieButton->setText(QApplication::translate("MainWindow", "Pie Chart", nullptr));
        lineButton->setText(QApplication::translate("MainWindow", "Line Chart", nullptr));
        close_1->setText(QApplication::translate("MainWindow", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
