#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

// savings account increases by an interest rate every month, allowing to accumulate money, but it imposes restrictions on withdrawals
class SavingsAccount: public Account {
public:
    SavingsAccount(const QString& number, const QString& pincode, const QString& phone, double initBalance, double interest=0);
    ~SavingsAccount();
    double interest() const;
private:
    double _interest;
};

#endif // SAVINGSACCOUNT_H
