#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const QString& number, const QString& pincode, const QString& phone, double initBalance,
                                 double maxBalance, const QString& excessReceiver) :
    Account(number, pincode, phone, initBalance), _maxBalance(maxBalance) {
    if (_maxBalance < 0) {
        throw BadAccount("Maximal balance < 0 at CheckingAccount::CheckingAccount");
    }
}

void CheckingAccount::doDeposit(double sum) {
    if (sum < 0) {
        throw BadAccount("Negative argument at CheckingAccount::deposit");
    }

    if (_maxBalance == 0) {
        _balance += sum;
        return;
    }

    double dif = _balance + sum - _maxBalance;
    if (dif > 0) {
        if (_excessReceiver == nullptr) {
            throw BadAccount("Call to excess receiving account at CheckingAccount::deposit, the account being set to nullptr");
        }
        _balance = _maxBalance;
        _excessReceiver->deposit(dif);
    } else {
        _balance += sum;
    }
}

double CheckingAccount::maxBalance() const {
    return _maxBalance;
}

CheckingAccount::~CheckingAccount() {
    _excessReceiver = nullptr;
    _maxBalance = 0;
}
