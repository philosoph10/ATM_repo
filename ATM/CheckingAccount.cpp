#include "CheckingAccount.h"
#include "clientbase.h"

CheckingAccount::CheckingAccount(const QString& number, const QString& pincode,
                                 const QString& phone, ClientBase* db, double initBalance,
                                 double maxBalance, const QString& excessReceiver) :
    Account(number, pincode, phone, db, initBalance), _maxBalance(maxBalance),
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
    if (_maxBalance == 0)
    {
        _balance += sum;
        _db->updateBalance(_number, _balance);
        return;
    }

    double dif = _balance + sum - _maxBalance;
    if (dif > 0)
    {
        Account* transferTo = _db->getAccount(_excessReceiver);
        if (transferTo == nullptr)
        {
            throw BadAccount("Call to non-existing excess receiving account at CheckingAccount::doDeposit");
        }
        _balance = _maxBalance;
        transferTo->deposit(dif);
    }
    else
    {
        _balance += sum;
    }
    _db->updateBalance(_number, _balance);
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

