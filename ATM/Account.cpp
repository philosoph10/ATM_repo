#include "Account.h"
#include <QDebug>
#include "clientbase.h"

Account::Account(const QString& number, const QString& pincode, const QString& email,
                 ClientBase* db, double initBalance) :
    _number(number), _pincode(pincode), _email(email), _db(db), _balance(initBalance)
{
    if (initBalance < 0)
    {
        throw BadAccount("Initial balance < 0 at Account::Account");
    }
}

void Account::withdraw(double sum)
{
    if (sum < 0)
    {
        throw BadAccount("Negative argument at Account::doWithdraw");
    }
    doWithdraw(sum);
}

void Account::deposit(double sum)
{
    if (sum < 0)
    {
        throw BadAccount("Negative argument at Account::doDeposit");
    }
    doDeposit(sum);
}

void Account::transfer(const QString& number, double sum)
{
    if (sum < 0)
    {
        throw BadAccount("Negative argument at Account::doTransfer");
    }
    if (sum > _balance)
    {
        throw BadAccount("Attempt to withdraw sum greater than balance at Account::doTransfer");
    }
    doTransfer(number, sum);
}

double Account::balance() const
{
    return _balance;
}

const QString& Account::number() const
{
    return _number;
}

const QString& Account::pincode() const
{
    return _pincode;
}

void Account::setPincode(const QString &newPincode)
{
    if (newPincode.length() != 4)
    {
        throw BadAccount("Pin-code of wrong length at Account::setPincode");
    }
}

const QString& Account::email() const
{
    return _email;
}

void Account::doWithdraw(double sum)
{
    if (sum > _balance)
    {
        throw BadAccount("Attempt to withdraw sum greater than balance at Account::doWithdraw");
    }
    _db->updateBalance(_number, _balance - sum);
    _balance -= sum;
}

void Account::doDeposit(double sum)
{
    _db->updateBalance(_number, _balance + sum);
    _balance += sum;
}

void Account::doTransfer(const QString& number, double sum)
{
    Account* to = _db->getAccount(number);
    if (to == nullptr)
    {
        throw BadAccount("Attempt to transfer to a non-existing account at Account::doTransfer");
    }
    withdraw(sum);
    to->deposit(sum);
}

Account::BadAccount::BadAccount(const QString& errorMessage) :
    _errorMessage(errorMessage)
{
}

void Account::BadAccount::showMessage() const
{
    qDebug() <<_errorMessage;
}
