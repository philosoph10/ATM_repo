#include "thewindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>
#include "clientbase.h"

int main(int argc, char *argv[])
{
//    ClientBase* db = new ClientBase("ClientBase.json");
//    Account* acc = db->getAccount("1234567890123456");
//    db->updateBalance("0987654321123456", 11000);
//    return 0;

//    QAndroidJniObject  activity  =   QAndroidJniObject :: callStaticObjectMethod ( "org/qtproject/qt5/android/QtNative" ,
//                                                                            "activity" ,
//                                                                            "()Landroid/app/Activity;" );

    QApplication a(argc, argv);
    TheWindow w;
    w.show();
    return a.exec();
}
