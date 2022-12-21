#include "clientbase.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "LineOfCreditAccount.h"

ClientBase::ClientBase(const QString& filepath): _filepath(filepath)
{
    update();
}

Account *ClientBase::getAccount(const QString &number)
{
    update();
    QJsonValue value = _kernel.value(QString("Accounts"));
    QJsonArray accounts = value.toArray();
    qDebug() << accounts.size() << '\n';
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject account = accounts[i].toObject();
        QString curNumber = account.value("Number").toString();
        if (curNumber != number) continue;
        QString type = account.value("Type").toString();
        if(type == "Checking")
        {
            return getCheckingAcc(account);
        }
        else if(type == "Savings")
        {
            return getSavingsAcc(account);
        }
        else
        {
            return getLineOfCreditAcc(account);
        }
    }
    return nullptr;
}

bool ClientBase::isCheckingAcc(const QString &number)
{
    QString accType = type(number);
    return accType == "Checking";
}

bool ClientBase::isSavingsAcc(const QString &number)
{
    QString accType = type(number);
    return accType == "Savings";
}

bool ClientBase::isLineOfCreditAcc(const QString &number)
{
    QString accType = type(number);
    return accType == "Line of Credit";
}

void ClientBase::updateBalance(const QString &number, double val)
{
    update();
    QJsonValue value = _kernel.value(QString("Accounts"));
    QJsonArray accounts = value.toArray();
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject account = accounts[i].toObject();
        QString curNumber = account.value("Number").toString();
        if (curNumber != number) continue;
        account.remove("Balance");
        account.insert("Balance", val);
        accounts.removeAt(i);
        accounts.insert(i, account);
        //qDebug() << accounts.size() << '\n';
        _kernel.remove("Accounts");
        _kernel.insert("Accounts", accounts);
        rewriteFile();
        return;
    }
}

void ClientBase::updateMaxBalance(const QString &number, double balance)
{
    update();
    QJsonValue value = _kernel.value(QString("Accounts"));
    QJsonArray accounts = value.toArray();
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject account = accounts[i].toObject();
        QString curNumber = account.value("Number").toString();
        if (curNumber != number) continue;
        if (account.contains("Max-balance")) account.remove("Max-balance");
        account.insert("Max-balance", balance);
        accounts.removeAt(i);
        accounts.insert(i, account);
        //qDebug() << accounts.size() << '\n';
        _kernel.remove("Accounts");
        _kernel.insert("Accounts", accounts);
        rewriteFile();
        return;
    }
}

void ClientBase::updateExcessReceiver(const QString &number, const QString &excessReceiver)
{
    update();
    QJsonValue value = _kernel.value(QString("Accounts"));
    QJsonArray accounts = value.toArray();
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject account = accounts[i].toObject();
        QString curNumber = account.value("Number").toString();
        if (curNumber != number) continue;
        if(account.contains("Excess-receiver")) account.remove("Excess-receiver");
        account.insert("Excess-receiver", excessReceiver);
        accounts.removeAt(i);
        accounts.insert(i, account);
        //qDebug() << accounts.size() << '\n';
        _kernel.remove("Accounts");
        _kernel.insert("Accounts", accounts);
        rewriteFile();
        return;
    }
}

void ClientBase::updateMinBalance(const QString &number, double val)
{
    update();
    QJsonValue value = _kernel.value(QString("Accounts"));
    QJsonArray accounts = value.toArray();
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject account = accounts[i].toObject();
        QString curNumber = account.value("Number").toString();
        if (curNumber != number) continue;
        if (account.contains("Min-balance")) account.remove("Min-balance");
        account.insert("Min-balance", val);
        accounts.removeAt(i);
        accounts.insert(i, account);
        //qDebug() << accounts.size() << '\n';
        _kernel.remove("Accounts");
        _kernel.insert("Accounts", accounts);
        rewriteFile();
        return;
    }
}

void ClientBase::updateBackup(const QString &number, const QString &backup)
{
    update();
    QJsonValue value = _kernel.value(QString("Accounts"));
    QJsonArray accounts = value.toArray();
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject account = accounts[i].toObject();
        QString curNumber = account.value("Number").toString();
        if (curNumber != number) continue;
        if(account.contains("Back-up")) account.remove("Back-up");
        account.insert("Back-up", backup);
        accounts.removeAt(i);
        accounts.insert(i, account);
        //qDebug() << accounts.size() << '\n';
        _kernel.remove("Accounts");
        _kernel.insert("Accounts", accounts);
        rewriteFile();
        return;
    }
}

void ClientBase::updatePincode(const QString &number, const QString &pincode)
{
    update();
    QJsonValue value = _kernel.value(QString("Accounts"));
    QJsonArray accounts = value.toArray();
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject account = accounts[i].toObject();
        QString curNumber = account.value("Number").toString();
        if (curNumber != number) continue;
        if(account.contains("Pin-code")) account.remove("Pin-code");
        account.insert("Pin-code", pincode);
        accounts.removeAt(i);
        accounts.insert(i, account);
        //qDebug() << accounts.size() << '\n';
        _kernel.remove("Accounts");
        _kernel.insert("Accounts", accounts);
        rewriteFile();
        return;
    }
}

void ClientBase::update()
{
    QString contents;
    QFile file(_filepath);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    contents = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(contents.toUtf8());
    _kernel = doc.object();
}

QString ClientBase::type(const QString &number)
{
    update();
    QJsonValue value = _kernel.value(QString("Accounts"));
    QJsonArray accounts = value.toArray();
    for (int i = 0; i < accounts.size(); ++i) {
        QJsonObject account = accounts[i].toObject();
        QString curNumber = account.value("Number").toString();
        if (curNumber != number) continue;
        return account.value("Type").toString();
    }
    return "";
}

Account *ClientBase::getCheckingAcc(const QJsonObject &account)
{
    QString number = account.value("Number").toString();
    QString pincode = account.value("Pin-code").toString();
    QString email = account.value("E-mail").toString();
    double balance = account.value("Balance").toDouble();
    if(account.contains("Max-balance"))
    {
        double maxBalance = account.value("Max-balance").toDouble();
        QString excessReceiver = account.value("Excess-receiver").toString();
        return new CheckingAccount(number, pincode, email, this, balance, maxBalance, excessReceiver);
    }
    return new CheckingAccount(number, pincode, email, this, balance);
}

Account *ClientBase::getSavingsAcc(const QJsonObject &account)
{
    QString number = account.value("Number").toString();
    QString pincode = account.value("Pin-code").toString();
    QString email = account.value("E-mail").toString();
    double balance = account.value("Balance").toDouble();
    return new SavingsAccount(number, pincode, email, this, balance);
}

Account *ClientBase::getLineOfCreditAcc(const QJsonObject &account)
{
    QString number = account.value("Number").toString();
    QString pincode = account.value("Pin-code").toString();
    QString email = account.value("E-mail").toString();
    double balance = account.value("Balance").toDouble();
    double minBalance = account.value("Min-balance").toDouble();
    QString backup = account.value("Back-up").toString();
    return new LineOfCreditAccount(number, pincode, email, this, balance, minBalance, backup);
}

void ClientBase::rewriteFile()
{
    QJsonDocument doc = QJsonDocument(_kernel);
    QFile file(_filepath);
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.close();
}
