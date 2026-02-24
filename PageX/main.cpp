#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Load QSS file
    QFile file(":/style.qss"); // If using Qt resource system
    // QFile file("style.qss"); // If using file path
    if(file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
    }

    MainWindow w;
    w.show();

    return app.exec();
}
