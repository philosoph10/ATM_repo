#include "thewindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TheWindow w;
    w.show();
    return a.exec();
}
