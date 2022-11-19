#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>

// the interface of a bank account
// every account has a number, a pin-code for access, an associated phone number (can be used to retrieve forgotten pin-code), and a balance (money)
class Account {
public:
    Account(const QString& number, const QString& pincode, const QString& phone, double initBalance=0);
    void withdraw(double);
    void deposit(double);
    void transfer(Account& to, double sum);
    double balance() const;
    const QString& number() const;
    const QString& pincode() const;
    void setPincode(const QString&);
    const QString& phone() const;
    virtual ~Account() {}
    class BadAccount
    {
    public:
        BadAccount(const QString&);
        ~BadAccount() {}
        void showMessage() const;
    private:
        const QString _errorMessage;
    };
protected:
    const QString _number;
    QString _pincode;
    QString _phone;
    double _balance;
private:
    virtual void doWithdraw(double);
    virtual void doDeposit(double);
    virtual void doTransfer(Account& to, double sum);
    virtual void doSetPincode() {}
};

#endif // ACCOUNT_H
