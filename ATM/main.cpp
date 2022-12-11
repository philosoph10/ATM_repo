#include "thewindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>
//#include "clientbase.h"
//#include "LineOfCreditAccount.h"

int main(int argc, char *argv[])
{
    //ClientBase* db = new ClientBase("ClientBase.json");
    //CheckingAccount* ca = dynamic_cast<CheckingAccount*>(db->getAccount("1234567890123456"));
    //ca->setMaxBalance(2800, "0987654321123456");
    //db->updateMaxBalance("1234567890123456", 2600);
    //db->updateExcessReceiver("1234567890123456", "0987654321123456");
    //LineOfCreditAccount* account = dynamic_cast<LineOfCreditAccount*>(db->getAccount("1234561234567890"));
//    try {
//        account->setBackup("0987654321123456");
//    } catch (const Account::BadAccount& ba) {
//        ba.showMessage();
//    }
    QApplication a(argc, argv);
    TheWindow w;
    w.show();
    return a.exec();
}
