/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *loginButton;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *numberLineEdit;
    QLabel *label_4;
    QLineEdit *pinLineEdit;
    QLabel *registerErrorLabel;
    QWidget *page_2;
    QLabel *label;
    QLabel *balanceLabelC;
    QPushButton *pushButton_2;
    QPushButton *putCashButtonC;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *logOutButtonC;
    QWidget *page_3;
    QStackedWidget *stackedWidget_2;
    QWidget *page_4;
    QPushButton *loginButton_2;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *numberLineEdit_2;
    QLabel *label_8;
    QLineEdit *pinLineEdit_2;
    QWidget *page_5;
    QLabel *label_9;
    QLabel *balanceLabelS;
    QPushButton *pushButton_6;
    QPushButton *putCashButtonS;
    QPushButton *pushButton_8;
    QPushButton *logOutButtonS;
    QWidget *page_6;
    QWidget *page_7;
    QStackedWidget *stackedWidget_3;
    QWidget *page_8;
    QPushButton *loginButton_3;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *numberLineEdit_3;
    QLabel *label_13;
    QLineEdit *pinLineEdit_3;
    QWidget *page_9;
    QLabel *label_14;
    QLabel *balanceLabelL;
    QPushButton *pushButton_9;
    QPushButton *putCashButtonL;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *logOutButtonL;
    QWidget *page_10;
    QWidget *page_11;
    QLabel *label_16;
    QPushButton *cancelPutCashButton;
    QLabel *label_17;
    QLineEdit *putCashLineEdit;
    QPushButton *confirmPutCashPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 401, 281));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName("page");
        loginButton = new QPushButton(page);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(280, 210, 70, 27));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 30, 80, 40));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 100, 130, 30));
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);
        numberLineEdit = new QLineEdit(page);
        numberLineEdit->setObjectName("numberLineEdit");
        numberLineEdit->setGeometry(QRect(205, 100, 113, 30));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 140, 130, 30));
        label_4->setFont(font1);
        pinLineEdit = new QLineEdit(page);
        pinLineEdit->setObjectName("pinLineEdit");
        pinLineEdit->setGeometry(QRect(205, 140, 113, 30));
        registerErrorLabel = new QLabel(page);
        registerErrorLabel->setObjectName("registerErrorLabel");
        registerErrorLabel->setGeometry(QRect(205, 170, 113, 12));
        QFont font2;
        font2.setPointSize(7);
        registerErrorLabel->setFont(font2);
        registerErrorLabel->setStyleSheet(QString::fromUtf8("color: red"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 30, 170, 40));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        balanceLabelC = new QLabel(page_2);
        balanceLabelC->setObjectName("balanceLabelC");
        balanceLabelC->setGeometry(QRect(130, 80, 150, 20));
        QFont font3;
        font3.setPointSize(14);
        balanceLabelC->setFont(font3);
        balanceLabelC->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 180, 80, 18));
        putCashButtonC = new QPushButton(page_2);
        putCashButtonC->setObjectName("putCashButtonC");
        putCashButtonC->setGeometry(QRect(40, 180, 80, 18));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(170, 140, 80, 18));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(130, 210, 150, 41));
        logOutButtonC = new QPushButton(page_2);
        logOutButtonC->setObjectName("logOutButtonC");
        logOutButtonC->setGeometry(QRect(10, 0, 80, 18));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget_2 = new QStackedWidget(page_3);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 0, 401, 281));
        stackedWidget_2->setStyleSheet(QString::fromUtf8(""));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        loginButton_2 = new QPushButton(page_4);
        loginButton_2->setObjectName("loginButton_2");
        loginButton_2->setGeometry(QRect(280, 210, 70, 27));
        label_6 = new QLabel(page_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(150, 30, 80, 40));
        label_6->setFont(font);
        label_7 = new QLabel(page_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 100, 130, 30));
        label_7->setFont(font1);
        numberLineEdit_2 = new QLineEdit(page_4);
        numberLineEdit_2->setObjectName("numberLineEdit_2");
        numberLineEdit_2->setGeometry(QRect(205, 100, 113, 30));
        label_8 = new QLabel(page_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 140, 130, 30));
        label_8->setFont(font1);
        pinLineEdit_2 = new QLineEdit(page_4);
        pinLineEdit_2->setObjectName("pinLineEdit_2");
        pinLineEdit_2->setGeometry(QRect(205, 140, 113, 30));
        stackedWidget_2->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_9 = new QLabel(page_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(130, 30, 170, 40));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);
        balanceLabelS = new QLabel(page_5);
        balanceLabelS->setObjectName("balanceLabelS");
        balanceLabelS->setGeometry(QRect(130, 80, 150, 20));
        balanceLabelS->setFont(font3);
        balanceLabelS->setAlignment(Qt::AlignCenter);
        pushButton_6 = new QPushButton(page_5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(280, 200, 80, 18));
        putCashButtonS = new QPushButton(page_5);
        putCashButtonS->setObjectName("putCashButtonS");
        putCashButtonS->setGeometry(QRect(30, 200, 80, 18));
        pushButton_8 = new QPushButton(page_5);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(160, 160, 80, 18));
        logOutButtonS = new QPushButton(page_5);
        logOutButtonS->setObjectName("logOutButtonS");
        logOutButtonS->setGeometry(QRect(10, 0, 80, 18));
        stackedWidget_2->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget_2->addWidget(page_6);
        stackedWidget->addWidget(page_3);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        stackedWidget_3 = new QStackedWidget(page_7);
        stackedWidget_3->setObjectName("stackedWidget_3");
        stackedWidget_3->setGeometry(QRect(0, 0, 401, 281));
        stackedWidget_3->setStyleSheet(QString::fromUtf8(""));
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        loginButton_3 = new QPushButton(page_8);
        loginButton_3->setObjectName("loginButton_3");
        loginButton_3->setGeometry(QRect(280, 210, 70, 27));
        label_11 = new QLabel(page_8);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(150, 30, 80, 40));
        label_11->setFont(font);
        label_12 = new QLabel(page_8);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(50, 100, 130, 30));
        label_12->setFont(font1);
        numberLineEdit_3 = new QLineEdit(page_8);
        numberLineEdit_3->setObjectName("numberLineEdit_3");
        numberLineEdit_3->setGeometry(QRect(205, 100, 113, 30));
        label_13 = new QLabel(page_8);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(50, 140, 130, 30));
        label_13->setFont(font1);
        pinLineEdit_3 = new QLineEdit(page_8);
        pinLineEdit_3->setObjectName("pinLineEdit_3");
        pinLineEdit_3->setGeometry(QRect(205, 140, 113, 30));
        stackedWidget_3->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        label_14 = new QLabel(page_9);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(100, 30, 210, 40));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);
        balanceLabelL = new QLabel(page_9);
        balanceLabelL->setObjectName("balanceLabelL");
        balanceLabelL->setGeometry(QRect(130, 80, 150, 20));
        balanceLabelL->setFont(font3);
        balanceLabelL->setAlignment(Qt::AlignCenter);
        pushButton_9 = new QPushButton(page_9);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(290, 180, 80, 18));
        putCashButtonL = new QPushButton(page_9);
        putCashButtonL->setObjectName("putCashButtonL");
        putCashButtonL->setGeometry(QRect(40, 180, 80, 18));
        pushButton_11 = new QPushButton(page_9);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(170, 140, 80, 18));
        pushButton_12 = new QPushButton(page_9);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(130, 210, 150, 41));
        logOutButtonL = new QPushButton(page_9);
        logOutButtonL->setObjectName("logOutButtonL");
        logOutButtonL->setGeometry(QRect(10, 0, 80, 18));
        stackedWidget_3->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        stackedWidget_3->addWidget(page_10);
        stackedWidget->addWidget(page_7);
        page_11 = new QWidget();
        page_11->setObjectName("page_11");
        label_16 = new QLabel(page_11);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(110, 50, 180, 30));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignCenter);
        cancelPutCashButton = new QPushButton(page_11);
        cancelPutCashButton->setObjectName("cancelPutCashButton");
        cancelPutCashButton->setGeometry(QRect(0, 0, 71, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("leftarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelPutCashButton->setIcon(icon);
        label_17 = new QLabel(page_11);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(70, 140, 100, 20));
        QFont font4;
        font4.setPointSize(13);
        label_17->setFont(font4);
        putCashLineEdit = new QLineEdit(page_11);
        putCashLineEdit->setObjectName("putCashLineEdit");
        putCashLineEdit->setGeometry(QRect(180, 140, 113, 20));
        confirmPutCashPushButton = new QPushButton(page_11);
        confirmPutCashPushButton->setObjectName("confirmPutCashPushButton");
        confirmPutCashPushButton->setGeometry(QRect(210, 170, 80, 18));
        stackedWidget->addWidget(page_11);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        stackedWidget_2->setCurrentIndex(1);
        stackedWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Account Pin-code:", nullptr));
        registerErrorLabel->setText(QCoreApplication::translate("MainWindow", "Incorrect number or pin", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Checking Account", nullptr));
        balanceLabelC->setText(QCoreApplication::translate("MainWindow", "Balance: xxx", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Obtain Cash", nullptr));
        putCashButtonC->setText(QCoreApplication::translate("MainWindow", "Put Cash", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Transfer Cash", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Money surfeit processing\n"
"service", nullptr));
        logOutButtonC->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        loginButton_2->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Account Pin-code:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Savings Account", nullptr));
        balanceLabelS->setText(QCoreApplication::translate("MainWindow", "Balance: xxx", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Obtain Cash", nullptr));
        putCashButtonS->setText(QCoreApplication::translate("MainWindow", "Put Cash", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Transfer Cash", nullptr));
        logOutButtonS->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        loginButton_3->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Account Pin-code:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Line of Credit Account", nullptr));
        balanceLabelL->setText(QCoreApplication::translate("MainWindow", "Balance: xxx", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Obtain Cash", nullptr));
        putCashButtonL->setText(QCoreApplication::translate("MainWindow", "Put Cash", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Transfer Cash", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Change backup card", nullptr));
        logOutButtonL->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Putting cash...", nullptr));
        cancelPutCashButton->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "Enter sum:", nullptr));
        confirmPutCashPushButton->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
