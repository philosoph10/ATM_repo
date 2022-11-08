#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

// savings account increases by an interest rate every month, allowing to accumulate money, but it imposes restrictions on cash obtaining and transferring money to other accounts
class SavingsAccount: public Account {
public:
    SavingsAccount(const QString& number, const QString& pincode, const QString& phone, double initSum, double interest=0);
    double interest() const;
    ~SavingsAccount();
};

#endif // SAVINGSACCOUNT_H
