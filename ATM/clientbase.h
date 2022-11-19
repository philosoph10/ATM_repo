#ifndef CLIENTBASE_H
#define CLIENTBASE_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QIODevice>
#include <QFile>
#include "Account.h"

class ClientBase
{
public:
    ClientBase(const QString& filepath);
    Account* getAccount(const QString& number);

private:
    void update();

private:
    QString _filepath;
    QJsonObject _kernel;
};

#endif // CLIENTBASE_H
