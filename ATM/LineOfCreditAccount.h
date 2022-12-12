#ifndef LINEOFCREDITACCOUNT_H
#define LINEOFCREDITACCOUNT_H
#include "Account.h"

// line of credit account has an option of setting the minimal balance,
// i.e. if the balance drops below a certain sum,
// it is augmented with money from a back-up account
class LineOfCreditAccount: public Account
{
public:
    LineOfCreditAccount(const QString& number, const QString& pincode, const QString& email,
                        ClientBase* db, double initBalance, double minBalance=0,
                        const QString& backup="");
    ~LineOfCreditAccount() {}
    double minBalance() const;
    void setBackup(const QString& backup);
private:
    double _minBalance;
    QString _backup;
    void doWithdraw(double);
};

#endif // LINEOFCREDITACCOUNT_H
