#include "mainwindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>
#include "clientbase.h"
#include "LineOfCreditAccount.h"

int main(int argc, char *argv[])
{
    ClientBase* db = new ClientBase("ClientBase.json");
    Account* first = db->getAccount("1234567890123456");
    Account* second = db->getAccount("0987654321123456");
    //second->withdraw(2);
    second->transfer("1234567890123456", 1000);
    //first->deposit(2000);
    //second->deposit(10000);
    //first->transfer("0987654321123456", 50);
    //CheckingAccount("1234567890123456", "5920", "0991234567", db, 650);
    //LineOfCreditAccount("1234561234567890", "0000", "+380994720018", db, 1000);
//    SavingsAccount("1234567812345678", "0000", "+380994720018", db, 1000);
//    db->updateBalance("0987654321123456", 11000);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
