#include "clientbase.h"
#include "CheckingAccount.h"
#include "LineOfCreditAccount.h"
#include "SavingsAccount.h"

#include <QTest>

class TestAccounts: public QObject
{
    Q_OBJECT
private slots:
    void checkConstructor();
    void checkWithdraw();
    void checkDeposit();
    void checkTransfer();
    void checkSetMaxBalance();
    void checkSetBackup();
};

void TestAccounts::checkConstructor()
{
    ClientBase* db = new ClientBase("ClientBase.json");

    bool success = true;
    try {
        CheckingAccount negativeInitBalance("0000000000000000", "0000", "name.last_name@gmail.com", db, -1);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        CheckingAccount smallMaxBalance("0000000000000000", "0000", "name.last_name@gmail.com", db, 50, 1);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        CheckingAccount noExcessReceiver("0000000000000000", "0000", "name.last_name@gmail.com", db, 50, 100);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        LineOfCreditAccount negMinBalance("0000000000000000", "0000", "name.last_name@gmail.com", db, 50, -1);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        SavingsAccount negInterest("0000000000000000", "0000", "name.last_name@gmail.com", db, 50, -1);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    delete db;
}

void TestAccounts::checkWithdraw()
{
    ClientBase* db = new ClientBase("ClientBase.json");

    CheckingAccount* ca = dynamic_cast<CheckingAccount*>(db->getAccount("1234567890123456"));
    LineOfCreditAccount* la = dynamic_cast<LineOfCreditAccount*>(db->getAccount("1234561234567890"));
    SavingsAccount* sa = dynamic_cast<SavingsAccount*>(db->getAccount("0987654321123456"));

    double checking_balance = ca->balance();
    ca->withdraw(checking_balance / 2);
    QCOMPARE(ca->balance(), checking_balance - checking_balance / 2);

    bool success = true;
    try {
        ca->withdraw(-1);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        ca->withdraw(1000000);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    double la_balance = la->balance();
    la->withdraw(0);
    QCOMPARE(la->balance(), la_balance);

    LineOfCreditAccount noBackup("1111111111111111", "0000", "name.last_name@gmail.com", db, 1000, 500);
    success = true;
    try {
        noBackup.withdraw(600);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        la->withdraw(1000000);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    double min_balance = la->minBalance();
    double savings_balance = sa->balance();
    la->withdraw(la->balance() - min_balance + 100);
    sa = dynamic_cast<SavingsAccount*>(db->getAccount("0987654321123456"));
    QCOMPARE(la->balance(), min_balance);
    QCOMPARE(sa->balance(), savings_balance - 100);

    double sa_balance = sa->balance();
    sa->withdraw(sa_balance / 2);
    QCOMPARE(sa->balance(), sa_balance - sa_balance / 2 * 1.01);

    delete db;
}

void TestAccounts::checkDeposit()
{
    ClientBase* db = new ClientBase("ClientBase.json");

    CheckingAccount* ca = dynamic_cast<CheckingAccount*>(db->getAccount("1234567890123456"));
    SavingsAccount* sa = dynamic_cast<SavingsAccount*>(db->getAccount("0987654321123456"));

    bool success = true;
    try {
        ca->deposit(-1);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    double sa_balance = sa->balance();
    sa->deposit(1000);
    QCOMPARE(sa->balance(), sa_balance + 1000);

    CheckingAccount noMaxBalance("0000000000000000", "1111", "name.last_name@ukma.edu.ua", db, 1000);
    noMaxBalance.deposit(1000);
    QCOMPARE(noMaxBalance.balance(), 2000);

    double ca_balance = ca->balance();
    ca->deposit(0);
    QCOMPARE(ca->balance(), ca_balance);

    sa_balance = sa->balance();
    ca->deposit(ca->maxBalance() - ca->balance() + 1000);
    sa = dynamic_cast<SavingsAccount*>(db->getAccount("0987654321123456"));
    QCOMPARE(ca->balance(), ca->maxBalance());
    QCOMPARE(sa->balance(), sa_balance + 1000);

    delete db;
}

void TestAccounts::checkTransfer()
{
    ClientBase* db = new ClientBase("ClientBase.json");

    db->updateBalance("1234567890123456", 2000);
    db->updateMaxBalance("1234567890123456", 2800);
    db->updateBalance("0987654321123456", 7000);
    db->updateBalance("1234561234567890", 3000);
    db->updateMinBalance("1234561234567890", 2000);

    LineOfCreditAccount* la = dynamic_cast<LineOfCreditAccount*>(db->getAccount("1234561234567890"));
    la->transfer("1234567890123456", 1500);

    CheckingAccount* ca = dynamic_cast<CheckingAccount*>(db->getAccount("1234567890123456"));
    la = dynamic_cast<LineOfCreditAccount*>(db->getAccount("1234561234567890"));
    SavingsAccount* sa = dynamic_cast<SavingsAccount*>(db->getAccount("0987654321123456"));

    QCOMPARE(ca->balance(), 2800);
    QCOMPARE(sa->balance(), 7200);
    QCOMPARE(la->balance(), 2000);

    delete db;
}

void TestAccounts::checkSetMaxBalance()
{
    ClientBase* db = new ClientBase("ClientBase.json");
    CheckingAccount toy("1111111111111111", "0000", "name.last_name@gmail.com", db, 1000);

    bool success = true;
    try {
        toy.setMaxBalance(-1);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        toy.setMaxBalance(3000);
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    SavingsAccount excessReceiver("0000000000000000", "1111", "name.last_name@ukma.edu.ua", db, 1000);
    success = true;
    try {
        toy.setMaxBalance(3000, "0000000000000000");
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    CheckingAccount* ca = dynamic_cast<CheckingAccount*>(db->getAccount("1234567890123456"));
    ca->setMaxBalance(0, "1234561234567890");
    QCOMPARE(ca->maxBalance(), 0);

    success = true;
    try {
        ca->setMaxBalance(1, "0987654321123456");
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    ca->setMaxBalance(3000, "0987654321123456");
    QCOMPARE(ca->maxBalance(), 3000);

    delete db;
}

void TestAccounts::checkSetBackup()
{
    ClientBase* db = new ClientBase("ClientBase.json");
    LineOfCreditAccount* la = dynamic_cast<LineOfCreditAccount*>(db->getAccount("1234561234567890"));

    bool success = true;
    try {
        la->setBackup("");
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        la->setBackup("0000000000000000");
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, false);

    success = true;
    try {
        la->setBackup("0987654321123456");
    } catch (const Account::BadAccount& ba) {
        success = false;
    }
    QCOMPARE(success, true);

    delete db;
}

QTEST_MAIN(TestAccounts)
#include "TestAccounts.moc"
