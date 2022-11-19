#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent, QDir databaseDir)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _workingAccount(nullptr)
{
    ui->setupUi(this);
    ui->stackedWidget->setStyleSheet("background-color: white");
    ui->stackedWidget->setCurrentIndex(0);
    setUpRegisterScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::registerCheck()
{
}

void MainWindow::setUpRegisterScreen()
{
    ui->numberLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,16}")));
    ui->pinLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,4}")));
}

void MainWindow::on_loginButton_clicked()
{
    // do :: get account from database
    QString number = ui->numberLineEdit->text();
    QString pinCode = ui->pinLineEdit->text();
    //workingAccount = ;
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_logOutButton_clicked()
{
    if (_workingAccount != nullptr) delete _workingAccount;
    _workingAccount = nullptr;
    ui->stackedWidget->setCurrentIndex(0);
}

