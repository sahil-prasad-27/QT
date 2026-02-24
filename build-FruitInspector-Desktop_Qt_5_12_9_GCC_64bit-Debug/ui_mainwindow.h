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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableDetections;
    QLabel *gpuLabel;
    QLabel *fpsLabel;
    QLabel *cameraLabel;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnStart;
    QPushButton *btnStop;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 700);
        MainWindow->setMinimumSize(QSize(1200, 700));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableDetections = new QTableWidget(widget);
        if (tableDetections->columnCount() < 3)
            tableDetections->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableDetections->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableDetections->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableDetections->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableDetections->setObjectName(QString::fromUtf8("tableDetections"));
        tableDetections->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableDetections->setColumnCount(3);
        tableDetections->horizontalHeader()->setVisible(true);

        verticalLayout->addWidget(tableDetections);

        gpuLabel = new QLabel(widget);
        gpuLabel->setObjectName(QString::fromUtf8("gpuLabel"));

        verticalLayout->addWidget(gpuLabel);

        fpsLabel = new QLabel(widget);
        fpsLabel->setObjectName(QString::fromUtf8("fpsLabel"));

        verticalLayout->addWidget(fpsLabel);


        verticalLayout_2->addLayout(verticalLayout);

        cameraLabel = new QLabel(widget);
        cameraLabel->setObjectName(QString::fromUtf8("cameraLabel"));
        cameraLabel->setMinimumSize(QSize(800, 600));
        cameraLabel->setStyleSheet(QString::fromUtf8("background-color: black;\n"
"color: white;\n"
""));
        cameraLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(cameraLabel);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnStart = new QPushButton(widget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        verticalLayout_3->addWidget(btnStart);

        btnStop = new QPushButton(widget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        verticalLayout_3->addWidget(btnStop);


        horizontalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_2->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fruit Inspector", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableDetections->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Fruit", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableDetections->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Confidence", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableDetections->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Time", nullptr));
        gpuLabel->setText(QApplication::translate("MainWindow", "GPU: Checking...", nullptr));
        fpsLabel->setText(QApplication::translate("MainWindow", "FPS: 0", nullptr));
        cameraLabel->setText(QApplication::translate("MainWindow", "Camera Off", nullptr));
        btnStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        btnStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
