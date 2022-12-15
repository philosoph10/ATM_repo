#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

// checking account has an option of setting maximal balance,
// i.e. if the balance exceeds a certain sum,
// the excess is automatically transfered to a different account
class CheckingAccount: public Account
{
public:
    // maxBalance = 0 means that maximal balance isn't set up,
    // excessReceiver should be an empty string in that case
    CheckingAccount(const QString& number, const QString& pincode, const QString& email,
                    ClientBase* db, double initBalance, double maxBalance=0,
                    const QString& excessReceiver="");
    double maxBalance() const;
    void setMaxBalance(double newMaxBalance, const QString& excessReceiver="");
    ~CheckingAccount() {}
private:
    double _maxBalance;
    QString _excessReceiver;
    void doDeposit(double);
};

#endif // CHECKINGACCOUNT_H
