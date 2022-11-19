#include "clientbase.h"

ClientBase::ClientBase(const QString& filepath): _filepath(filepath)
{
    update();
}

Account *ClientBase::getAccount(const QString &number)
{

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
