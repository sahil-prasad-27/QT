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
#include <QtWidgets/QGridLayout>
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
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *usernameLineEdit2;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLineEdit2;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
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
        widget->setGeometry(QRect(130, 220, 225, 89));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        usernameLineEdit2 = new QLabel(widget);
        usernameLineEdit2->setObjectName(QString::fromUtf8("usernameLineEdit2"));

        gridLayout->addWidget(usernameLineEdit2, 0, 0, 1, 1);

        usernameLineEdit = new QLineEdit(widget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        gridLayout->addWidget(usernameLineEdit, 0, 1, 1, 1);

        passwordLineEdit2 = new QLabel(widget);
        passwordLineEdit2->setObjectName(QString::fromUtf8("passwordLineEdit2"));

        gridLayout->addWidget(passwordLineEdit2, 1, 0, 1, 1);

        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 1, 1, 1, 1);

        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        gridLayout->addWidget(loginButton, 2, 0, 1, 2);

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
        usernameLineEdit2->setText(QApplication::translate("MainWindow", "UserName:", nullptr));
        usernameLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Enter  username", nullptr));
        passwordLineEdit2->setText(QApplication::translate("MainWindow", "Password", nullptr));
        passwordLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Enter password", nullptr));
        loginButton->setText(QApplication::translate("MainWindow", "LogIn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
