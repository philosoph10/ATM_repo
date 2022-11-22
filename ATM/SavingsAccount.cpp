#include "SavingsAccount.h"
#include <QDebug>

SavingsAccount::SavingsAccount(const QString& number, const QString& pincode,
                               const QString& phone, double initBalance, double interest) :
    Account(number, pincode, phone, initBalance), _interest(interest), _timer(new QTimer()),
    _lastDate(QDate::currentDate())
{
    if (_interest < 0)
    {
        throw BadAccount("Interest < 0 at SavingsAccount::SavingsAccount");
    }
    connect(_timer, SIGNAL(timeout()), this, SLOT(updateBalance()));
    _timer->start(86400000);
}

SavingsAccount::~SavingsAccount()
{
    delete _timer;
}

double SavingsAccount::interest() const
{
    return _interest;
}

double &SavingsAccount::interest()
{
    return _interest;
}

void SavingsAccount::updateBalance()
{
    QDate current = QDate::currentDate();
    if (_lastDate.day() == current.day() && _lastDate.month() % 12 == current.month() - 1)
    {
        _lastDate = current;
        _balance *= 1 + _interest / 100;
    }
}
