#include "SavingsAccount.h"
#include "clientbase.h"
#include <QDebug>

SavingsAccount::SavingsAccount(const QString& number, const QString& pincode,
                               const QString& email, ClientBase* db, double initBalance) :
    Account(number, pincode, email, db, initBalance)
{
}

SavingsAccount::~SavingsAccount()
{

}

void SavingsAccount::doWithdraw(double sum)
{
    double total = sum * (1 + _COMMISSION);
    if (total > _balance)
    {
        throw BadAccount("Not enough money on balance at SavingsAccount::doWithdraw");
    }
    _db->updateBalance(_number, _balance - total);
    _balance -= total;
}
