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
    void registerCheck();

    void on_loginButton_clicked();

    void on_logOutButton_clicked();

private:
    Ui::MainWindow *ui;
    Account* _workingAccount;

private:
    void setUpRegisterScreen();
};
#endif // MAINWINDOW_H
