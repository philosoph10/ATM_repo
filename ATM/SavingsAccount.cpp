#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const QString& number, const QString& pincode,
                               const QString& phone, double initBalance, double interest) :
    Account(number, pincode, phone, initBalance), _interest(interest) {
    if (_interest < 0) {
        throw BadAccount("Interest < 0 at SavingsAccount::SavingsAccount");
    }
}

SavingsAccount::~SavingsAccount() {
    _interest = 0;
}

double SavingsAccount::interest() const {
    return _interest;
}
