#ifndef THEWINDOW_H
#define THEWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QDir>
#include <QMessageBox>
#include "Account.h"
#include "CheckingAccount.h"
#include "LineOfCreditAccount.h"
#include "clientbase.h"
#include "mailsender.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TheWindow; }
QT_END_NAMESPACE

class TheWindow : public QMainWindow
{
    Q_OBJECT

public:
    TheWindow(QWidget *parent = nullptr, QDir path = QDir::current());
    ~TheWindow();

private slots:
    Account* registerCheck();

    void on_loginButton_clicked();

    void performLogout();

    void performPasswordRecovery();

    void prepareResetPin();

    void prepareToPutCash();

    void prepareToObtainCash();

    void prepareToTransferMoney();

    void prepareToSurfeitProcessing();

    void prepareToChangingBackup();

    void cancelEnteringMail();

    void cancelCodeVerification();

    void cancelPinReset();

    void cancelPuttingCash();

    void cancelObtainingCash();

    void cancelTransfer();

    void cancelSurfeitProcessing();

    void cancelChangingBackup();

    void verifyEmailAndSendCode();

    void sendCode();

    void resetPincode();

private:
    Ui::TheWindow *ui;
    Account* _workingAccount;
    ClientBase* _db;
    MailSender* _sender;
    QString* _recoveryCode;

private:
    void setUpRegisterScreen();
    void setUpEmailEnteringScreen();
    void setUpCodeVerificationScreen();
    void setUpPinCodeResetScreen();
    void setUpCheckingAccScreen();
    void setUpSavingsAccScreen();
    void setUpLineOfCreditAccScreen();
    void setUpPutCashScreen();
    void setUpObtainCashScreen();
    void setUpTransferScreen();
    void setUpSurfeitProcessing();
    void setUpChangingBackup();
    void jumpToCorrectScreen();
    void putCash();
    void obtainCash();
    void transferMoney();
    void surfeitProcessing();
    void changeBackup();
};
#endif // THEWINDOW_H
