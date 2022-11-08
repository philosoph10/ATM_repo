#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>

// the interface of a bank account
// every account has a number, a pin-code for access, an associated phone number (can be used to retrieve forgotten pin-code), and a balance (money)
class Account {
public:
    Account(const QString& number, const QString& pincode, const QString& phone, double initBalance=0);
    void obtainCash(double);
    void putCash(double);
    void transfer(const Account& to);
    double balance() const;
    const QString& number() const;
    const QString& pincode() const;
    void setPincode(const QString&);
    const QString& phone() const;
    virtual ~Account();
};

#endif // ACCOUNT_H
