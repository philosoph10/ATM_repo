#include "thewindow.h"
#include "ui_thewindow.h"
#include <QDebug>
#include <QRegularExpressionValidator>

TheWindow::TheWindow(QWidget *parent, QDir databaseDir)
    : QMainWindow(parent)
    , ui(new Ui::TheWindow)
    , _workingAccount(nullptr)
    , _db(new ClientBase(databaseDir.absolutePath() + "/ClientBase.json"))
{
    ui->setupUi(this);
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
}

TheWindow::~TheWindow()
{
    delete ui;
    if(_workingAccount != nullptr) delete _workingAccount;
    delete _db;
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
    ui->registerErrorLabel->hide();
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
    _workingAccount->deposit(ui->putCashLineEdit->text().toDouble());
    ui->putCashLineEdit->clear();
    _db->updateBalance(_workingAccount->number(), _workingAccount->balance());
    jumpToCorrectScreen();
}

void TheWindow::obtainCash()
{
    _workingAccount->withdraw(ui->obtainCashLineEdit->text().toDouble());
    ui->obtainCashLineEdit->clear();
    _db->updateBalance(_workingAccount->number(), _workingAccount->balance());
    jumpToCorrectScreen();
}

void TheWindow::transferMoney()
{
//    Account* to = _db->getAccount(ui->transferCardLineEdit->text());
//    _workingAccount->transfer(&to, ui->obtainCashLineEdit->text().toDouble());
//    ui->obtainCashLineEdit->clear();
//    _db->updateBalance(_workingAccount->number(), _workingAccount->balance());
    //    jumpToCorrectScreen();
}

void TheWindow::surfeitProcessing()
{
    // implement!
    return;
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
    qDebug() << "Cancelling surfeit processing!\n";
    jumpToCorrectScreen();
}

