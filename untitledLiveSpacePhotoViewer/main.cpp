#include <QApplication>
#include "LiveImageWidget.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    LiveImageWidget w;
    w.show();

    return app.exec();
}
