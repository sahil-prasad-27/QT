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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditAge;
    QLineEdit *lineEditName;
    QTableView *tableViewUsers;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonUpdate;
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
        lineEditAge = new QLineEdit(centralwidget);
        lineEditAge->setObjectName(QString::fromUtf8("lineEditAge"));

        gridLayout->addWidget(lineEditAge, 1, 1, 1, 1);

        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout->addWidget(lineEditName, 1, 0, 1, 1);

        tableViewUsers = new QTableView(centralwidget);
        tableViewUsers->setObjectName(QString::fromUtf8("tableViewUsers"));

        gridLayout->addWidget(tableViewUsers, 0, 0, 1, 2);

        pushButtonAdd = new QPushButton(centralwidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        gridLayout->addWidget(pushButtonAdd, 2, 0, 1, 1);

        pushButtonUpdate = new QPushButton(centralwidget);
        pushButtonUpdate->setObjectName(QString::fromUtf8("pushButtonUpdate"));

        gridLayout->addWidget(pushButtonUpdate, 2, 1, 1, 1);

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
        lineEditAge->setPlaceholderText(QApplication::translate("MainWindow", "age", nullptr));
        lineEditName->setPlaceholderText(QApplication::translate("MainWindow", "name", nullptr));
        pushButtonAdd->setText(QApplication::translate("MainWindow", "submit", nullptr));
        pushButtonUpdate->setText(QApplication::translate("MainWindow", "update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
