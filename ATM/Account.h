#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>

class ClientBase;

// the interface of a bank account
// every account has a number, a pin-code for access,
// an associated email address (can be used to retrieve forgotten pin-code),
// and a balance (money)
// also every bank account belongs to some database
class Account
{
public:
    Account(const QString& number, const QString& pincode, const QString& email, ClientBase* db,
            double initBalance=0);
    void withdraw(double);
    void deposit(double);
    void transfer(const QString& number, double sum);
    double balance() const;
    const QString& number() const;
    const QString& pincode() const;
    void setPincode(const QString&);
    const QString& email() const;
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
    QString _email;
    ClientBase* _db;
    double _balance;
private:
    virtual void doWithdraw(double);
    virtual void doDeposit(double);
    virtual void doTransfer(const QString& number, double sum);
};

#endif // ACCOUNT_H
