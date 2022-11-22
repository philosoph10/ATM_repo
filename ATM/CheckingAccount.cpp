#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const QString& number, const QString& pincode,
                                 const QString& phone, double initBalance,
                                 double maxBalance, const QString& excessReceiver) :
    Account(number, pincode, phone, initBalance), _maxBalance(maxBalance),
    _excessReceiver(excessReceiver)
{
    if (_maxBalance < 0)
    {
        throw BadAccount("Maximal balance < 0 at CheckingAccount::CheckingAccount");
    }
    if (_maxBalance > 0 && _excessReceiver == "")
    {
        throw BadAccount("Set maximal balance but not the excess receiving account at CheckingAccount::CheckingAccount");
    }
}

void CheckingAccount::doDeposit(double sum)
{
    if (sum < 0)
    {
        throw BadAccount("Negative argument at CheckingAccount::deposit");
    }

    if (_maxBalance == 0)
    {
        _balance += sum;
        return;
    }

    double dif = _balance + sum - _maxBalance;
    if (dif > 0) {
        //TODO: handle the case where excess receiver is invalid
//        if (_excessReceiver == nullptr)
//        {
//            throw BadAccount("Call to excess receiving account at CheckingAccount::deposit, the account being set to nullptr");
//        }
        _balance = _maxBalance;
        //TODO: _excessReceiver->deposit(dif);
    }
    else
    {
        _balance += sum;
    }
}

double CheckingAccount::maxBalance() const
{
    return _maxBalance;
}

void CheckingAccount::setMaxBalance(double newMaxBalance, const QString &excessReceiver)
{
    if (newMaxBalance < 0)
    {
        throw BadAccount("Negative argument at CheckingAccount::setMaxBalance");
    }
    if (newMaxBalance > 0 && _excessReceiver == "" && excessReceiver == "")
    {
        throw BadAccount("No excess receiver at CheckingAccount::setMaxBalance");
    }
    _maxBalance = newMaxBalance;
    if (excessReceiver != "")
    {
        _excessReceiver = excessReceiver;
    }
}

