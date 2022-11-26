#include "thewindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>
#include "clientbase.h"

int main(int argc, char *argv[])
{
    ClientBase* db = new ClientBase("ClientBase.json");
    db->updateMaxBalance("1234567890123456", 2600);
    db->updateExcessReceiver("1234567890123456", "0987654321123456");

    QApplication a(argc, argv);
    TheWindow w;
    w.show();
    return a.exec();
}
