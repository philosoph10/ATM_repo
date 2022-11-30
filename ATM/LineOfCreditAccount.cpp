#include "LineOfCreditAccount.h"
#include "clientbase.h"

LineOfCreditAccount::LineOfCreditAccount(const QString& number, const QString& pincode,
                                         const QString& email, ClientBase* db,
                                         double initBalance, double minBalance,
                                         const QString& backup) :
    Account(number, pincode, email, db, initBalance), _minBalance(minBalance), _backup(backup)
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

void LineOfCreditAccount::setBackup(const QString &backup)
{
    if (_minBalance > 0 && backup == "")
    {
        throw BadAccount("No back-up despite set minimal balance at LineOfCreditAccount::setBackup");
    }
    if (backup != "")
    {
        Account* backupAccount = _db->getAccount(backup);
        if (backupAccount == nullptr)
        {
            throw BadAccount("Non-existing back-up account at LineOfCreditAccount::setBackup");
        }
    }
    _backup = backup;
    _db->updateBackup(_number, _backup);
}

void LineOfCreditAccount::doWithdraw(double sum)
{
    double left = _balance - sum;
    double dif = _minBalance - left;
    if (dif <= 0)
    {
        _db->updateBalance(_number, left);
        _balance = left;
        return;
    }
    Account* backupAccount = _db->getAccount(_backup);
    if (backupAccount == nullptr)
    {
        throw BadAccount("No backup account when needed at LineOfCreditAccount::doWithdraw");
    }
    if (backupAccount->balance() < dif)
    {
        throw BadAccount("Not enough money on backup account at LineOfCreditAccount::doWithdraw");
    }
    _db->updateBalance(_backup, backupAccount->balance() - dif);
    _db->updateBalance(_number, _minBalance);
    _balance = _minBalance;
}
