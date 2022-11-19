#include "LineOfCreditAccount.h"

LineOfCreditAccount::LineOfCreditAccount(const QString& number, const QString& pincode,
                                         const QString& phone, double initBalance,
                                         double minBalance) :
    Account(number, pincode, phone, initBalance), _minBalance(minBalance) {
    if (_minBalance < 0) {
        throw BadAccount("Minimal balance < 0 at LineOfCreditAccount::LineOfCreditAccount");
    }
}

LineOfCreditAccount::~LineOfCreditAccount() {
    _minBalance = 0;
}

double LineOfCreditAccount::minBalance() const {
    return _minBalance;
}
