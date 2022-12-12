#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <QTimer>
#include <QTime>
#include "Account.h"
#include <QObject>
//#include "qobjectdefs.h"

// savings account increases by an interest rate every month, allowing to accumulate money,
// but it imposes restrictions on withdrawals
class SavingsAccount: public Account
{
public:
    SavingsAccount(const QString& number, const QString& pincode, const QString& email,
                   ClientBase* db, double initBalance, double interest=0);
    ~SavingsAccount();
    double interest() const;
    double& interest();
private:
    double _interest;
    const double _COMMISSION = 0.01;
    void doWithdraw(double);
};

#endif // SAVINGSACCOUNT_H
