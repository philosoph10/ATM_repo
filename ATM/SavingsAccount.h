#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <QTimer>
#include <QTime>
#include "Account.h"
#include <QObject>
//#include "qobjectdefs.h"

// savings account increases by an interest rate every month, allowing to accumulate money,
// but it imposes restrictions on withdrawals
class SavingsAccount: public QObject, public Account
{

    Q_OBJECT

public:
    SavingsAccount(const QString& number, const QString& pincode, const QString& phone,
                   double initBalance, double interest=0);
    ~SavingsAccount();
    double interest() const;
    double& interest();
public slots:
    void updateBalance();
private:
    double _interest;
    QTimer* _timer;
    QDate _lastDate;
};

#endif // SAVINGSACCOUNT_H
