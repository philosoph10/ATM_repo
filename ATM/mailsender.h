#ifndef MAILSENDER_H
#define MAILSENDER_H
#include "SmtpMime"

class MailSender
{
private:
    QString _login;
    QString _password;
    QString _name;
    SmtpClient _smtp;

public:
    MailSender(QString login, QString password, QString name="Me", QString host="smtp.gmail.com",
               int port=465, SmtpClient::ConnectionType connectionType=SmtpClient::SslConnection);
    bool sendMail(QString receiverAddress, QString receiverName, QString subject, QString body);
};

#endif // MAILSENDER_H
