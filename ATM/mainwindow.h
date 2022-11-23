#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QDir>
#include "Account.h"
#include "clientbase.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, QDir path = QDir::current());
    ~MainWindow();

private slots:
    Account* registerCheck();

    void on_loginButton_clicked();

    void performLogout();

    void prepareToPutCash();

    void cancelPuttingCash();

private:
    Ui::MainWindow *ui;
    Account* _workingAccount;
    ClientBase* _db;

private:
    void setUpRegisterScreen();
    void setUpCheckingAccScreen();
    void setUpSavingsAccScreen();
    void setUpLineOfCreditAccScreen();
    void setUpObtainCashScreen();
    void jumpToCorrectScreen();
    void putCash();
};
#endif // MAINWINDOW_H
