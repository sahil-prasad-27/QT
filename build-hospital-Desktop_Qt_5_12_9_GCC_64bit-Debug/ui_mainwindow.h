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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(832, 490);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 20, 551, 51));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:40px;\n"
"background:transparent;\n"
"color:Black;\n"
"}"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(380, 110, 191, 25));
        lineEdit->setStyleSheet(QString::fromUtf8("QlineEdit{\n"
"font-size:17px;\n"
"color:blue;\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 110, 141, 21));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:17px;\n"
"color:blue;\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 160, 141, 21));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:17px;\n"
"color:blue;\n"
"}"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(380, 160, 191, 25));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QlineEdit{\n"
"font-size:17px;\n"
"color:blue;\n"
"}"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(380, 210, 191, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 210, 161, 21));
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:17px;\n"
"color:blue;\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 290, 89, 25));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15px;\n"
"color:blue;\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 290, 89, 25));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15px;\n"
"color:blue;\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 290, 89, 25));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15px;\n"
"color:red;\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 250, 161, 21));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:17px;\n"
"color:blue;\n"
"}"));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(380, 250, 191, 25));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QlineEdit{\n"
"font-size:17px;\n"
"color:blue;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 832, 22));
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
        label->setText(QApplication::translate("MainWindow", "Hospital Management System", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Patient ID", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Patient Name", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Select Group", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "O+", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "O-", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "A+", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "A-", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "B+", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "B-", nullptr));

        label_4->setText(QApplication::translate("MainWindow", "Patient Blood Group", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "OK", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Search", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Cancel", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Disease:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
