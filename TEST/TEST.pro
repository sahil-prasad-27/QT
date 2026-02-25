QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../Documents/report_window/graph_factory/abstractGraph.cpp \
    ../../Documents/report_window/graph_factory/barChart.cpp \
    ../../Documents/report_window/graph_factory/graphFactory.cpp \
    ../../Documents/report_window/graph_factory/lineChart.cpp \
    ../../Documents/report_window/graph_factory/pieChart.cpp \
    ../../Documents/report_window/infoWidget.cpp \
    ../../Documents/report_window/irsgraph.cpp \
    ../../Documents/report_window/irsgraphFactory.cpp \
    ../../Documents/report_window/qcustomplot/qcustomplot.cpp \
    ../../Documents/report_window/reportWindow.cpp \
    ../../Documents/report_window/reportWindowSetting.cpp \
    ../../Documents/report_window/sorting_pieChart.cpp \
    ../../Documents/report_window/systemData_lineChart.cpp \
    ../../Documents/report_window/valveUsage_barChart.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../Documents/report_window/graphButtons.h \
    ../../Documents/report_window/graph_factory/abstractGraph.h \
    ../../Documents/report_window/graph_factory/barChart.h \
    ../../Documents/report_window/graph_factory/graphFactory.h \
    ../../Documents/report_window/graph_factory/lineChart.h \
    ../../Documents/report_window/graph_factory/pieChart.h \
    ../../Documents/report_window/infoWidget.h \
    ../../Documents/report_window/irsgraph.h \
    ../../Documents/report_window/irsgraphFactory.h \
    ../../Documents/report_window/qcustomplot/qcustomplot.h \
    ../../Documents/report_window/reportWindow.h \
    ../../Documents/report_window/reportWindowSetting.h \
    ../../Documents/report_window/sorting_pieChart.h \
    ../../Documents/report_window/systemData_lineChart.h \
    ../../Documents/report_window/valveUsage_barChart.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
