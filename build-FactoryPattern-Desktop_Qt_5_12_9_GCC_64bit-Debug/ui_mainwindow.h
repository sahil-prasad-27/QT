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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *graphWidget;
    QPushButton *btnBar;
    QPushButton *btnLine;
    QPushButton *btnPie;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("/* ===== Main Window ===== */\n"
"QMainWindow {\n"
"    background-color: #f4f6f9;\n"
"}\n"
"\n"
"/* ===== Central Widget ===== */\n"
"QWidget#centralwidget {\n"
"    background-color: #f4f6f9;\n"
"}\n"
"\n"
"/* ===== Menu Bar ===== */\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    color: #2c3e50;\n"
"    border-bottom: 1px solid #dcdcdc;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e53935;\n"
"    color: white;\n"
"}\n"
"\n"
"/* ===== Status Bar ===== */\n"
"QStatusBar {\n"
"    background-color: #ffffff;\n"
"    color: #555;\n"
"    border-top: 1px solid #dcdcdc;\n"
"}\n"
"\n"
"/* ===== Rounded Modern Buttons ===== */\n"
"QPushButton {\n"
"    background-color: #ffffff;\n"
"    color: #2c3e50;\n"
"    border: 2px solid #e53935;\n"
"    border-radius: 18px;        /* Rounded shape */\n"
"    padding: 6px 16px;          /* Smaller padding */\n"
"    font-size: 12px;            /* Smaller font */\n"
"    font-weight: 600;\n"
"    min-height: 32px;           /* Proper button hei"
                        "ght */\n"
"}\n"
"\n"
"/* Hover Effect */\n"
"QPushButton:hover {\n"
"    background-color: #e53935;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Pressed Effect */\n"
"QPushButton:pressed {\n"
"    background-color: #c62828;\n"
"    border: 2px solid #c62828;\n"
"}\n"
"\n"
"/* ===== Graph Widget ===== */\n"
"#graphWidget {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #e53935;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"/* ===== Specific Buttons Bold ===== */\n"
"#btnBar, #btnLine, #btnPie {\n"
"    font-weight: 700;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphWidget = new QWidget(centralwidget);
        graphWidget->setObjectName(QString::fromUtf8("graphWidget"));
        graphWidget->setStyleSheet(QString::fromUtf8("/* ===== Main Window ===== */\n"
"QMainWindow {\n"
"    background-color: #f4f6f9; /* Soft light grey */\n"
"}\n"
"\n"
"/* ===== Central Widget ===== */\n"
"QWidget#centralwidget {\n"
"    background-color: #f4f6f9; /* Matching background with main window */\n"
"}\n"
"\n"
"/* ===== Menu Bar ===== */\n"
"QMenuBar {\n"
"    background-color: #ffffff; /* Clean white */\n"
"    color: #34495e; /* Dark grey, professional */\n"
"    border-bottom: 1px solid #e1e8ed; /* Light border */\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #3498db; /* Soft blue (calming, professional) */\n"
"    color: white;\n"
"}\n"
"\n"
"/* ===== Status Bar ===== */\n"
"QStatusBar {\n"
"    background-color: #ffffff;\n"
"    color: #7f8c8d; /* Lighter grey for a more subtle status text */\n"
"    border-top: 1px solid #e1e8ed;\n"
"}\n"
"\n"
"/* ===== Rounded Modern Buttons ===== */\n"
"QPushButton {\n"
"    background-color: #ffffff; /* White background */\n"
"    color: #34495e; /* Dark grey text */\n"
"    border: 2p"
                        "x solid #34495e; /* Dark grey border for a professional look */\n"
"    border-radius: 18px;        /* Rounded corners */\n"
"    padding: 6px 16px;          /* Smaller padding */\n"
"    font-size: 12px;            /* Smaller font */\n"
"    font-weight: 600;           /* Semi-bold text */\n"
"    min-height: 32px;           /* Proper button height */\n"
"}\n"
"\n"
"/* Hover Effect */\n"
"QPushButton:hover {\n"
"    background-color: #34495e;  /* Dark grey background on hover */\n"
"    color: white;               /* White text on hover */\n"
"}\n"
"\n"
"/* Pressed Effect */\n"
"QPushButton:pressed {\n"
"    background-color: #2c3e50;  /* Even darker grey when pressed */\n"
"    border: 2px solid #2c3e50;  /* Matching border on press */\n"
"}\n"
"\n"
"/* ===== Graph Widget ===== */\n"
"#graphWidget {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #34495e;  /* Dark grey border */\n"
"    border-radius: 10px;        /* Rounded corners */\n"
"}\n"
"\n"
"/* ===== Specific Buttons Bold ===== */\n"
"#"
                        "btnBar, #btnLine, #btnPie {\n"
"    font-weight: 700; /* Keep these bold for emphasis */\n"
"}"));

        verticalLayout->addWidget(graphWidget);

        btnBar = new QPushButton(centralwidget);
        btnBar->setObjectName(QString::fromUtf8("btnBar"));

        verticalLayout->addWidget(btnBar);

        btnLine = new QPushButton(centralwidget);
        btnLine->setObjectName(QString::fromUtf8("btnLine"));

        verticalLayout->addWidget(btnLine);

        btnPie = new QPushButton(centralwidget);
        btnPie->setObjectName(QString::fromUtf8("btnPie"));

        verticalLayout->addWidget(btnPie);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnBar->setText(QApplication::translate("MainWindow", "Bar Chart", nullptr));
        btnLine->setText(QApplication::translate("MainWindow", "Line Chart", nullptr));
        btnPie->setText(QApplication::translate("MainWindow", "Pie Chart", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
