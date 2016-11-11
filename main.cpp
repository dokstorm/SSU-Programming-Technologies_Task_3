#include <QtGlobal>
#if QT_VERSION < 0x050000
#include <QtGui>
#else
#endif
#include <QApplication>

#include "app.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}
