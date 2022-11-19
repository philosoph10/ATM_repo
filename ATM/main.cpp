#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    SavingsAccount sa("2222222222222222", "0000", "+380977439838", 10000);
    CheckingAccount ca("1111111111111111", "1111", "+380994720018", 900);
    //ca.withdraw(400);
    ca.deposit(500);
    qDebug() << ca.balance();
    qDebug() << sa.balance();
    ca.transfer(sa, 500);
    qDebug() << ca.balance();
    qDebug() << sa.balance();
    return a.exec();
}
