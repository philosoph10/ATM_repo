#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <QTimer>
#include <QTime>
#include "Account.h"
#include <QObject>

// commission is taken at every withdrawal from a savings account
class SavingsAccount: public Account
{
public:
    SavingsAccount(const QString& number, const QString& pincode, const QString& email,
                   ClientBase* db, double initBalance);
    ~SavingsAccount();
private:
    const double _COMMISSION = 0.01;
    void doWithdraw(double);
};

#endif // SAVINGSACCOUNT_H
