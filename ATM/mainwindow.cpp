#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent, QDir databaseDir)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    setUpObtainCashScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
    if(_workingAccount != nullptr) delete _workingAccount;
    delete _db;
}

Account* MainWindow::registerCheck()
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

void MainWindow::setUpRegisterScreen()
{
    ui->numberLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,16}")));
    ui->pinLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{4}")));
    ui->numberLineEdit->setPlaceholderText("xxxxxxxxxxxxxxxx");
    ui->pinLineEdit->setPlaceholderText("xxxx");
    connect(ui->pinLineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_loginButton_clicked);
    ui->registerErrorLabel->hide();
}

void MainWindow::setUpCheckingAccScreen()
{
    connect(ui->logOutButtonC, &QPushButton::clicked, this, &MainWindow::performLogout);
    connect(ui->putCashButtonC, &QPushButton::clicked, this, &MainWindow::prepareToPutCash);
}

void MainWindow::setUpSavingsAccScreen()
{
    connect(ui->logOutButtonS, &QPushButton::clicked, this, &MainWindow::performLogout);
    connect(ui->putCashButtonS, &QPushButton::clicked, this, &MainWindow::prepareToPutCash);
}

void MainWindow::setUpLineOfCreditAccScreen()
{
    connect(ui->logOutButtonL, &QPushButton::clicked, this, &MainWindow::performLogout);
    connect(ui->putCashButtonL, &QPushButton::clicked, this, &MainWindow::prepareToPutCash);
}

void MainWindow::setUpObtainCashScreen()
{
    connect(ui->putCashLineEdit, &QLineEdit::returnPressed, this, &MainWindow::putCash);
    connect(ui->confirmPutCashPushButton, &QPushButton::clicked, this, &MainWindow::putCash);
    connect(ui->cancelPutCashButton, &QPushButton::clicked, this, &MainWindow::cancelPuttingCash);
    // not necessarily 2 numbers after .
    ui->putCashLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+(\.[0-9]{0,2})?")));
}

void MainWindow::jumpToCorrectScreen()
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

void MainWindow::putCash()
{
    _workingAccount->deposit(ui->putCashLineEdit->text().toDouble());
    ui->putCashLineEdit->clear();
    _db->updateBalance(_workingAccount->number(), _workingAccount->balance());
    jumpToCorrectScreen();
}

void MainWindow::on_loginButton_clicked()
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


void MainWindow::performLogout()
{
    if (_workingAccount != nullptr) delete _workingAccount;
    _workingAccount = nullptr;
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::prepareToPutCash()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::cancelPuttingCash()
{
    jumpToCorrectScreen();
}

