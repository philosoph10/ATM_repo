#include "thewindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>
#include "SmtpMime"
//#include "clientbase.h"
//#include "LineOfCreditAccount.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TheWindow w;
    w.show();
    return a.exec();
}
