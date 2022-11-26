#ifndef CLIENTBASE_H
#define CLIENTBASE_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QIODevice>
#include <QFile>
#include "Account.h"
//#include "CheckingAccount.h"
//#include "SavingsAccount.h"
//#include "LineOfCreditAccount.h"

class ClientBase
{
public:
    ClientBase(const QString& filepath);
    Account* getAccount(const QString& number);
    bool isCheckingAcc(const QString& number);
    bool isSavingsAcc(const QString& number);
    bool isLineOfCreditAcc(const QString& number);
    void updateBalance(const QString& number, double val);
    void updateMaxBalance(const QString& number, double balance);
    void updateExcessReceiver(const QString& number, const QString& excessReceiver);

private:
    void update();
    QString type(const QString& number);
    Account* getCheckingAcc(const QJsonObject& account);
    Account* getSavingsAcc(const QJsonObject& account);
    Account* getLineOfCreditAcc(const QJsonObject& account);
    void rewriteFile();

private:
    QString _filepath;
    QJsonObject _kernel;
};

#endif // CLIENTBASE_H
