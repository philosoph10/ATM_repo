#include "thewindow.h"
#include "ui_thewindow.h"
#include <QDebug>
#include <QRegularExpressionValidator>
#include <QRandomGenerator>

TheWindow::TheWindow(QWidget *parent, QDir databaseDir)
    : QMainWindow(parent)
    , ui(new Ui::TheWindow)
    , _workingAccount(nullptr)
    , _db(new ClientBase(databaseDir.absolutePath() + "/ClientBase.json"))
    , _sender(new MailSender("atm.moop@gmail.com", "vnmqmwwkeudmxrha"))
    , _recoveryCode(nullptr)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(401, 281));
    ui->stackedWidget->setStyleSheet("background-color: white");
    ui->stackedWidget->setCurrentIndex(0);
    setUpRegisterScreen();
    setUpCheckingAccScreen();
    setUpSavingsAccScreen();
    setUpLineOfCreditAccScreen();
    setUpPutCashScreen();
    setUpObtainCashScreen();
    setUpTransferScreen();
    setUpSurfeitProcessing();
    setUpChangingBackup();
    setUpEmailEnteringScreen();
    setUpCodeVerificationScreen();
    setUpPinCodeResetScreen();
//    bool success = _sender->sendMail("theophil2002@gmail.com", "theophil", "Qt message", "Read me carefully!");
//    qDebug() << "Success: " << success << '\n';
}

TheWindow::~TheWindow()
{
    delete ui;
    if(_workingAccount != nullptr)
    {
        delete _workingAccount;
    }
    if (_db != nullptr) delete _db;
    if(_sender != nullptr) delete _sender;
    if(_recoveryCode != nullptr)
    {
        delete _recoveryCode;
    }
}

Account* TheWindow::registerCheck()
{
    QString number = ui->numberLineEdit->text();
    QString pincode = ui->pinLineEdit->text();
    Account* acc = _db->getAccount(number);
    if(acc != nullptr) {
        QString realPin = acc->pincode();
        if(pincode == realPin) return acc;
    }
    return nullptr;
}

void TheWindow::setUpRegisterScreen()
{
    ui->numberLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,16}")));
    ui->pinLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{4}")));
    ui->numberLineEdit->setPlaceholderText("xxxxxxxxxxxxxxxx");
    ui->pinLineEdit->setPlaceholderText("xxxx");
    connect(ui->pinLineEdit, &QLineEdit::returnPressed, this, &TheWindow::on_loginButton_clicked);
    connect(ui->forgottenPasswordPushButton, &QPushButton::clicked, this, &TheWindow::performPasswordRecovery);
    ui->registerErrorLabel->hide();
}

void TheWindow::setUpEmailEnteringScreen()
{
    connect(ui->cancelRecoveryButton, &QPushButton::clicked, this, &TheWindow::cancelEnteringMail);
    connect(ui->sendCodeButton, &QPushButton::clicked, this, &TheWindow::verifyEmailAndSendCode);
    connect(ui->emailLineEdit, &QLineEdit::returnPressed, this, &TheWindow::verifyEmailAndSendCode);
    ui->numberLineEditForRecovery->setPlaceholderText("xxxxxxxxxxxxxxxx");
    ui->emailLineEdit->setPlaceholderText("myaddress@example.com");
    ui->numberLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,16}")));
    ui->emailErrorLabel->hide();
}

void TheWindow::setUpCodeVerificationScreen()
{
    connect(ui->cancelCodeSendingButton, &QPushButton::clicked, this, &TheWindow::cancelCodeVerification);
    connect(ui->resendCodeButton, &QPushButton::clicked, this, &TheWindow::sendCode);
    connect(ui->prepareResetCodeButton, &QPushButton::clicked, this, &TheWindow::prepareResetPin);
    connect(ui->recoveryCodeLineEdit, &QLineEdit::returnPressed, this, &TheWindow::prepareResetPin);
    ui->codeErrorLabel->hide();
    ui->recoveryCodeLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{6}")));
}

void TheWindow::setUpPinCodeResetScreen()
{
    connect(ui->cancelPinResetButton, &QPushButton::clicked, this, &TheWindow::cancelPinReset);
    connect(ui->confirmNewPinButton, &QPushButton::clicked, this, &TheWindow::resetPincode);
    connect(ui->repeatPinLineEdit, &QLineEdit::returnPressed, this, &TheWindow::resetPincode);
    ui->newPinLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{4}")));
    ui->repeatPinLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{4}")));
    ui->pinsMismatchErrorLabel->hide();
}

void TheWindow::setUpCheckingAccScreen()
{
    connect(ui->logOutButtonC, &QPushButton::clicked, this, &TheWindow::performLogout);
    connect(ui->putCashButtonC, &QPushButton::clicked, this, &TheWindow::prepareToPutCash);
    connect(ui->obtainCashButtonC, &QPushButton::clicked, this, &TheWindow::prepareToObtainCash);
    connect(ui->transferButtonC, &QPushButton::clicked, this, &TheWindow::prepareToTransferMoney);
    connect(ui->surfeitProcessingButton, &QPushButton::clicked, this, &TheWindow::prepareToSurfeitProcessing);
}

void TheWindow::setUpSavingsAccScreen()
{
    connect(ui->logOutButtonS, &QPushButton::clicked, this, &TheWindow::performLogout);
    connect(ui->putCashButtonS, &QPushButton::clicked, this, &TheWindow::prepareToPutCash);
    connect(ui->obtainCashButtonS, &QPushButton::clicked, this, &TheWindow::prepareToObtainCash);
    connect(ui->transferButtonS, &QPushButton::clicked, this, &TheWindow::prepareToTransferMoney);
}

void TheWindow::setUpLineOfCreditAccScreen()
{
    connect(ui->logOutButtonL, &QPushButton::clicked, this, &TheWindow::performLogout);
    connect(ui->putCashButtonL, &QPushButton::clicked, this, &TheWindow::prepareToPutCash);
    connect(ui->obtainCashButtonL, &QPushButton::clicked, this, &TheWindow::prepareToObtainCash);
    connect(ui->transferButtonL, &QPushButton::clicked, this, &TheWindow::prepareToTransferMoney);
    connect(ui->changeBackupButton, &QPushButton::clicked, this, &TheWindow::prepareToChangingBackup);
}

void TheWindow::setUpPutCashScreen()
{
    connect(ui->putCashLineEdit, &QLineEdit::returnPressed, this, &TheWindow::putCash);
    connect(ui->confirmPutCashPushButton, &QPushButton::clicked, this, &TheWindow::putCash);
    connect(ui->cancelPutCashButton, &QPushButton::clicked, this, &TheWindow::cancelPuttingCash);
    ui->putCashLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+(\.[0-9]{0,2})?")));
}

void TheWindow::setUpObtainCashScreen()
{
    connect(ui->obtainCashLineEdit, &QLineEdit::returnPressed, this, &TheWindow::obtainCash);
    connect(ui->confirmObtainCashPushButton, &QPushButton::clicked, this, &TheWindow::obtainCash);
    connect(ui->cancelObtainCashButton, &QPushButton::clicked, this, &TheWindow::cancelObtainingCash);
    ui->obtainCashLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+(\.[0-9]{0,2})?")));
}

void TheWindow::setUpTransferScreen()
{
    connect(ui->transferLineEdit, &QLineEdit::returnPressed, this, &TheWindow::transferMoney);
    connect(ui->confirmTransferPushButton, &QPushButton::clicked, this, &TheWindow::transferMoney);
    connect(ui->cancelTransferButton, &QPushButton::clicked, this, &TheWindow::cancelTransfer);
    ui->transferCardLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,16}")));
    ui->transferLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+(\.[0-9]{0,2})?")));
}

void TheWindow::setUpSurfeitProcessing()
{
    connect(ui->confirmSurfeitProcessingPushButton, &QPushButton::clicked, this, &TheWindow::surfeitProcessing);
    connect(ui->cancelSurfeitProcessingButton, &QPushButton::clicked, this, &TheWindow::cancelSurfeitProcessing);
    ui->surfeitReceiverLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,16}")));
    ui->maxBalanceLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+(\.[0-9]{0,2})?")));
}

void TheWindow::setUpChangingBackup()
{
    connect(ui->confirmChangeBackupButton, &QPushButton::clicked, this, &TheWindow::changeBackup);
    connect(ui->cancelChangeBackupButton, &QPushButton::clicked, this, &TheWindow::cancelChangingBackup);
    ui->changeBackupCardLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,16}")));
}

void TheWindow::jumpToCorrectScreen()
{
    if(_db->isCheckingAcc(_workingAccount->number()))
    {
        ui->balanceLabelC->setText("Balance: " + QString::number(_workingAccount->balance()));
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(_db->isSavingsAcc(_workingAccount->number()))
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->balanceLabelS->setText("Balance: " + QString::number(_workingAccount->balance()));
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(3);
        ui->balanceLabelL->setText("Balance: " + QString::number(_workingAccount->balance()));
    }
}

void TheWindow::putCash()
{
    try{
        _workingAccount->deposit(ui->putCashLineEdit->text().toDouble());
    }
    catch(const Account::BadAccount& err) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error occured while processing your request.\nWe are sorry "
                                      "for the inconvenience.");
        messageBox.setFixedSize(500,200);
    }
    ui->putCashLineEdit->clear();
    jumpToCorrectScreen();
}

void TheWindow::obtainCash()
{
    try {
        _workingAccount->withdraw(ui->obtainCashLineEdit->text().toDouble());
    }
    catch(const Account::BadAccount& err) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error occured while processing your request.\nWe are sorry "
                                      "for the inconvenience.");
        messageBox.setFixedSize(500,200);
    }
    ui->obtainCashLineEdit->clear();
    jumpToCorrectScreen();
}

void TheWindow::transferMoney()
{
    double sum = ui->transferLineEdit->text().toDouble();
    QString receiver = ui->transferCardLineEdit->text();
    try{
        _workingAccount->transfer(receiver, sum);
        _workingAccount = _db->getAccount(_workingAccount->number());
    }
    catch(const Account::BadAccount& err) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error occured while processing your request.\nWe are sorry "
                                      "for the inconvenience.");
        messageBox.setFixedSize(500,200);
    }
    ui->transferLineEdit->clear();
    jumpToCorrectScreen();
}

void TheWindow::surfeitProcessing()
{
    double maxBalance = ui->maxBalanceLineEdit->text().toDouble();
    QString excessReceiver = ui->surfeitReceiverLineEdit->text();
    try {
        if (maxBalance == 0) throw Account::BadAccount("Maximal balance is zero.");
        CheckingAccount* workingCheckingAcc = dynamic_cast<CheckingAccount*>(_workingAccount);
        workingCheckingAcc->setMaxBalance(maxBalance, excessReceiver);
    }
    catch(const Account::BadAccount& err) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error occured while processing your request.\nWe are sorry "
                                      "for the inconvenience.");
        messageBox.setFixedSize(500,200);
    }
    ui->maxBalanceLineEdit->clear();
    ui->surfeitReceiverLineEdit->clear();
    jumpToCorrectScreen();
}

void TheWindow::changeBackup()
{
    QString backupCard = ui->changeBackupCardLineEdit->text();
    try {
        LineOfCreditAccount* workingLineOfCreditAcc = dynamic_cast<LineOfCreditAccount*>(_workingAccount);
        workingLineOfCreditAcc->setBackup(backupCard);
    }
    catch(const Account::BadAccount& err) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error occured while processing your request.\nWe are sorry "
                                      "for the inconvenience.");
        messageBox.setFixedSize(500,200);
    }
    ui->changeBackupCardLineEdit->clear();
    jumpToCorrectScreen();
}

void TheWindow::on_loginButton_clicked()
{
    Account* acc = registerCheck();
    if (acc == nullptr) {
        ui->registerErrorLabel->show();
        return;
    }
    _workingAccount = acc;
    ui->registerErrorLabel->hide();
    ui->pinLineEdit->clear();
    jumpToCorrectScreen();
}


void TheWindow::performLogout()
{
    if (_workingAccount != nullptr) delete _workingAccount;
    _workingAccount = nullptr;
    ui->stackedWidget->setCurrentIndex(0);
}

void TheWindow::performPasswordRecovery()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void TheWindow::prepareResetPin()
{
    if(ui->recoveryCodeLineEdit->text() != *_recoveryCode)
    {
        ui->codeErrorLabel->show();
        return;
    }
    ui->stackedWidget->setCurrentIndex(11);
    ui->recoveryCodeLineEdit->clear();
    ui->codeErrorLabel->hide();
}

void TheWindow::prepareToPutCash()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void TheWindow::prepareToObtainCash()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void TheWindow::prepareToTransferMoney()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void TheWindow::prepareToSurfeitProcessing()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void TheWindow::prepareToChangingBackup()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void TheWindow::cancelEnteringMail()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->numberLineEditForRecovery->clear();
    ui->emailLineEdit->clear();
    ui->emailErrorLabel->hide();
}

void TheWindow::cancelCodeVerification()
{
    ui->stackedWidget->setCurrentIndex(0);
    if(_recoveryCode != nullptr) delete _recoveryCode;
    _recoveryCode = nullptr;
    ui->recoveryCodeLineEdit->clear();
    ui->codeErrorLabel->hide();
}

void TheWindow::cancelPinReset()
{
    ui->stackedWidget->setCurrentIndex(0);
    if(_recoveryCode != nullptr) delete _recoveryCode;
    _recoveryCode = nullptr;
    ui->newPinLineEdit->clear();
    ui->repeatPinLineEdit->clear();
    ui->pinsMismatchErrorLabel->hide();
}

void TheWindow::cancelPuttingCash()
{
    jumpToCorrectScreen();
}

void TheWindow::cancelObtainingCash()
{
    jumpToCorrectScreen();
}

void TheWindow::cancelTransfer()
{
    jumpToCorrectScreen();
}

void TheWindow::cancelSurfeitProcessing()
{
    jumpToCorrectScreen();
}

void TheWindow::cancelChangingBackup()
{
    jumpToCorrectScreen();
}

void TheWindow::verifyEmailAndSendCode()
{
    _workingAccount = _db->getAccount(ui->numberLineEditForRecovery->text());
    if (_workingAccount == nullptr)
    {
        ui->emailErrorLabel->show();
        return;
    }
    if(_workingAccount->email() != ui->emailLineEdit->text())
    {
        ui->emailErrorLabel->show();
        return;
    }
    ui->numberLineEditForRecovery->clear();
    ui->emailLineEdit->clear();
    ui->emailErrorLabel->hide();
    sendCode();
    ui->stackedWidget->setCurrentIndex(10);
}

void TheWindow::sendCode()
{
    if (_sender != nullptr)
    {
        delete _sender;
    }
    _sender = new MailSender("atm.moop@gmail.com", "vnmqmwwkeudmxrha");
    int codeVal = QRandomGenerator::system()->bounded(1000000);
    QString code = QString::number(codeVal);
    while(code.length() < 6) code = '0' + code;
    QString body = "Use this code to change your pin-code: " + code;
    qDebug() << "Receiver = " << _workingAccount->email() << '\n';
    _sender->sendMail(_workingAccount->email(), "Dear Client", "Pincode Recovery", body);
    QMessageBox messageBox;
    messageBox.information(0,"Important","A code was sent to your email.\nPlease go check your mailbox!");
    messageBox.setFixedSize(500,200);
    if(_recoveryCode != nullptr) delete _recoveryCode;
    _recoveryCode = new QString(code);
}

void TheWindow::resetPincode()
{
    QString pincode = ui->newPinLineEdit->text();
    if(pincode != ui->repeatPinLineEdit->text())
    {
        ui->pinsMismatchErrorLabel->show();
        return;
    }
    try {
        _workingAccount->setPincode(pincode);
    }
    catch (const Account::BadAccount& err) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error occured while processing your request.\nWe are sorry "
                                      "for the inconvenience.");
        messageBox.setFixedSize(500,200);
        return;
    }
    ui->pinsMismatchErrorLabel->hide();
    ui->newPinLineEdit->clear();
    ui->repeatPinLineEdit->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

