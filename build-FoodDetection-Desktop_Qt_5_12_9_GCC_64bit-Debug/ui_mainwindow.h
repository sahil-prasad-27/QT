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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *videoLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *exitBtn;
    QPushButton *reportBtn;
    QPushButton *browseBtn;
    QLabel *fpsLabel;
    QLabel *statusLabel;
    QTextEdit *reportTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1268, 904);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(141, 40, 625, 531));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        videoLabel = new QLabel(layoutWidget);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoLabel->sizePolicy().hasHeightForWidth());
        videoLabel->setSizePolicy(sizePolicy);
        videoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(videoLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startBtn = new QPushButton(layoutWidget);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));

        horizontalLayout->addWidget(startBtn);

        stopBtn = new QPushButton(layoutWidget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));

        horizontalLayout->addWidget(stopBtn);

        exitBtn = new QPushButton(layoutWidget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout->addWidget(exitBtn);

        reportBtn = new QPushButton(layoutWidget);
        reportBtn->setObjectName(QString::fromUtf8("reportBtn"));

        horizontalLayout->addWidget(reportBtn);

        browseBtn = new QPushButton(layoutWidget);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));

        horizontalLayout->addWidget(browseBtn);

        fpsLabel = new QLabel(layoutWidget);
        fpsLabel->setObjectName(QString::fromUtf8("fpsLabel"));

        horizontalLayout->addWidget(fpsLabel);

        statusLabel = new QLabel(layoutWidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        horizontalLayout->addWidget(statusLabel);


        verticalLayout->addLayout(horizontalLayout);

        reportTextEdit = new QTextEdit(centralwidget);
        reportTextEdit->setObjectName(QString::fromUtf8("reportTextEdit"));
        reportTextEdit->setGeometry(QRect(810, 90, 391, 351));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        reportTextEdit->setFont(font);
        reportTextEdit->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1268, 22));
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
        videoLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        startBtn->setText(QApplication::translate("MainWindow", "Start", nullptr));
        stopBtn->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        exitBtn->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        reportBtn->setText(QApplication::translate("MainWindow", "Generate Report", nullptr));
        browseBtn->setText(QApplication::translate("MainWindow", "Browse Folder", nullptr));
        fpsLabel->setText(QApplication::translate("MainWindow", "FPS: 0", nullptr));
        statusLabel->setText(QApplication::translate("MainWindow", "Status: Idle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
