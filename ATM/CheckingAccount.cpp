#include "CheckingAccount.h"
#include "clientbase.h"

CheckingAccount::CheckingAccount(const QString& number, const QString& pincode,
                                 const QString& email, ClientBase* db, double initBalance,
                                 double maxBalance, const QString& excessReceiver) :
    Account(number, pincode, email, db, initBalance), _maxBalance(maxBalance),
    _excessReceiver(excessReceiver)
{
    if (_maxBalance != 0 && _maxBalance < _balance)
    {
        throw BadAccount("Maximal balance less than init balance at CheckingAccount::CheckingAccount");
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
    if (newMaxBalance != 0 && newMaxBalance < _balance)
    {
        throw BadAccount("Attempt to set maximal balance less than current balance at CheckingAccount::setMaxBalance");
    }
    if (newMaxBalance > 0 && _excessReceiver == "" && excessReceiver == "")
    {
        throw BadAccount("No excess receiver at CheckingAccount::setMaxBalance");
    }
    if (excessReceiver != "")
    {
        Account* receiver = _db->getAccount(excessReceiver);
        if (receiver == nullptr)
        {
            throw BadAccount("Non-existing excess-receiving account at CheckingAccount::setMaxBalance");
        }
        _excessReceiver = excessReceiver;
        _db->updateExcessReceiver(_number, _excessReceiver);
    }
    _maxBalance = newMaxBalance;
    _db->updateMaxBalance(_number, _maxBalance);
}

