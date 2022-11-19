#include "mainwindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug() << QDir::current().path() << '\n';
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
