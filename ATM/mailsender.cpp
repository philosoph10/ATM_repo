#include "mailsender.h"

MailSender::MailSender(QString login, QString password, QString name, QString host, int port,
                       SmtpClient::ConnectionType connectionType):
    _login(login), _password(password), _name(name), _smtp(host, port, connectionType)
{
}

bool MailSender::sendMail(QString receiverAddress, QString receiverName, QString subject, QString body)
{
//    MimeMessage message;

//    EmailAddress sender(_login, _name);
//    message.setSender(sender);

//    EmailAddress to(receiverAddress, receiverName);
//    message.addRecipient(to);

//    message.setSubject(subject);

//    MimeText text;
//    text.setText(body);

//    message.addPart(&text);

//    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
//    smtp.connectToHost();
//    if (!smtp.waitForReadyConnected()) return false;
//    smtp.login(_login, _password);
//    qDebug() << "Connected to host...\n";
//    smtp.sendMail(message);
//    if (!smtp.waitForMailSent()) return false;
//    smtp.quit();
//    return true;
    MimeMessage message;

    EmailAddress sender(_login, "ATM");
    message.setSender(sender);

    EmailAddress to(receiverAddress, receiverName);
    message.addRecipient(to);

    message.setSubject(subject);

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText(body);

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail
    //SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    _smtp.connectToHost();
    if (!_smtp.waitForReadyConnected()) {
        qDebug() << "Failed to connect to host!";
        return -1;
    }

    _smtp.login(_login, _password);
    if (!_smtp.waitForAuthenticated()) {
        qDebug() << "Failed to login!";
        return false;
    }

    _smtp.sendMail(message);
    if (!_smtp.waitForMailSent()) {
        qDebug() << "Failed to send mail!";
        return false;
    }

    _smtp.quit();
    return true;
}

