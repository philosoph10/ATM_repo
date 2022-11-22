#include "Account.h"
#include <QDebug>

Account::Account(const QString& number, const QString& pincode, const QString& phone,
                 double initBalance) :
    _number(number), _pincode(pincode), _phone(phone), _balance(initBalance)
{
    if (initBalance < 0)
    {
        throw BadAccount("Initial balance < 0 at Account::Account");
    }
}

void Account::withdraw(double sum)
{
    doWithdraw(sum);
}

void Account::deposit(double sum)
{
    doDeposit(sum);
}

void Account::transfer(Account& to, double sum)
{
    doTransfer(to, sum);
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

QString &Account::pincode()
{
    return _pincode;
}

const QString& Account::phone() const
{
    return _phone;
}

QString &Account::phone()
{
    return _phone;
}

void Account::doWithdraw(double sum)
{
    if (sum < 0)
    {
        throw BadAccount("Negative argument at Account::doWithdraw");
    }
    if (sum > _balance)
    {
        throw BadAccount("Attempt to withdraw sum greater than balance at Account::doWithdraw");
    }
    _balance -= sum;
}

void Account::doDeposit(double sum)
{
    if (sum < 0)
    {
        throw BadAccount("Negative argument at Account::doDeposit");
    }
    _balance += sum;
}

void Account::doTransfer(Account& to, double sum)
{
    if (sum < 0)
    {
        throw BadAccount("Negative argument at Account::doTransfer");
    }
    if (sum > _balance)
    {
        throw BadAccount("Attempt to withdraw sum greater than balance at Account::doTransfer");
    }
    withdraw(sum);
    to.deposit(sum);
}

Account::BadAccount::BadAccount(const QString& errorMessage) :
    _errorMessage(errorMessage)
{
}

void Account::BadAccount::showMessage() const
{
    qDebug() <<_errorMessage;
}
