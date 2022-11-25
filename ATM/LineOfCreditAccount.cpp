#include "LineOfCreditAccount.h"

LineOfCreditAccount::LineOfCreditAccount(const QString& number, const QString& pincode,
                                         const QString& phone, ClientBase* db,
                                         double initBalance, double minBalance) :
    Account(number, pincode, phone, db, initBalance), _minBalance(minBalance)
{
    if (_minBalance < 0)
    {
        throw BadAccount("Minimal balance < 0 at LineOfCreditAccount::LineOfCreditAccount");
    }
}

double LineOfCreditAccount::minBalance() const
{
    return _minBalance;
}
