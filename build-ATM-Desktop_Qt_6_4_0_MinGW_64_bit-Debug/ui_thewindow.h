/********************************************************************************
** Form generated from reading UI file 'thewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEWINDOW_H
#define UI_THEWINDOW_H

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

class Ui_TheWindow
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
    QPushButton *obtainCashButtonC;
    QPushButton *putCashButtonC;
    QPushButton *transferButtonC;
    QPushButton *surfeitProcessingButton;
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
    QPushButton *obtainCashButtonS;
    QPushButton *putCashButtonS;
    QPushButton *transferButtonS;
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
    QPushButton *obtainCashButtonL;
    QPushButton *putCashButtonL;
    QPushButton *transferButtonL;
    QPushButton *pushButton_12;
    QPushButton *logOutButtonL;
    QWidget *page_10;
    QWidget *page_11;
    QLabel *label_16;
    QPushButton *cancelPutCashButton;
    QLabel *label_17;
    QLineEdit *putCashLineEdit;
    QPushButton *confirmPutCashPushButton;
    QWidget *page_12;
    QPushButton *confirmObtainCashPushButton;
    QLabel *label_18;
    QPushButton *cancelObtainCashButton;
    QLineEdit *obtainCashLineEdit;
    QLabel *label_19;
    QWidget *page_13;
    QLabel *label_20;
    QPushButton *confirmTransferPushButton;
    QPushButton *cancelTransferButton;
    QLineEdit *transferLineEdit;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *transferCardLineEdit;
    QWidget *page_14;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *surfeitReceiverLineEdit;
    QLineEdit *maxBalanceLineEdit;
    QPushButton *confirmSurfeitProcessingPushButton;
    QPushButton *cancelSurfeitProcessingButton;
    QWidget *page_15;
    QLineEdit *transferCardLineEdit_2;
    QPushButton *cancelTransferButton_2;
    QLabel *label_26;
    QPushButton *confirmTransferPushButton_2;
    QLabel *label_27;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TheWindow)
    {
        if (TheWindow->objectName().isEmpty())
            TheWindow->setObjectName("TheWindow");
        TheWindow->resize(400, 300);
        centralwidget = new QWidget(TheWindow);
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
        obtainCashButtonC = new QPushButton(page_2);
        obtainCashButtonC->setObjectName("obtainCashButtonC");
        obtainCashButtonC->setGeometry(QRect(290, 180, 80, 18));
        putCashButtonC = new QPushButton(page_2);
        putCashButtonC->setObjectName("putCashButtonC");
        putCashButtonC->setGeometry(QRect(40, 180, 80, 18));
        transferButtonC = new QPushButton(page_2);
        transferButtonC->setObjectName("transferButtonC");
        transferButtonC->setGeometry(QRect(160, 140, 90, 18));
        surfeitProcessingButton = new QPushButton(page_2);
        surfeitProcessingButton->setObjectName("surfeitProcessingButton");
        surfeitProcessingButton->setGeometry(QRect(130, 210, 150, 41));
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
        label_9->setGeometry(QRect(110, 40, 170, 40));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);
        balanceLabelS = new QLabel(page_5);
        balanceLabelS->setObjectName("balanceLabelS");
        balanceLabelS->setGeometry(QRect(120, 90, 150, 20));
        balanceLabelS->setFont(font3);
        balanceLabelS->setAlignment(Qt::AlignCenter);
        obtainCashButtonS = new QPushButton(page_5);
        obtainCashButtonS->setObjectName("obtainCashButtonS");
        obtainCashButtonS->setGeometry(QRect(280, 200, 80, 18));
        putCashButtonS = new QPushButton(page_5);
        putCashButtonS->setObjectName("putCashButtonS");
        putCashButtonS->setGeometry(QRect(30, 200, 80, 18));
        transferButtonS = new QPushButton(page_5);
        transferButtonS->setObjectName("transferButtonS");
        transferButtonS->setGeometry(QRect(150, 160, 90, 18));
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
        obtainCashButtonL = new QPushButton(page_9);
        obtainCashButtonL->setObjectName("obtainCashButtonL");
        obtainCashButtonL->setGeometry(QRect(290, 180, 80, 18));
        putCashButtonL = new QPushButton(page_9);
        putCashButtonL->setObjectName("putCashButtonL");
        putCashButtonL->setGeometry(QRect(40, 180, 80, 18));
        transferButtonL = new QPushButton(page_9);
        transferButtonL->setObjectName("transferButtonL");
        transferButtonL->setGeometry(QRect(160, 140, 90, 18));
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
        page_12 = new QWidget();
        page_12->setObjectName("page_12");
        confirmObtainCashPushButton = new QPushButton(page_12);
        confirmObtainCashPushButton->setObjectName("confirmObtainCashPushButton");
        confirmObtainCashPushButton->setGeometry(QRect(210, 170, 80, 18));
        label_18 = new QLabel(page_12);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(110, 50, 180, 30));
        label_18->setFont(font);
        label_18->setAlignment(Qt::AlignCenter);
        cancelObtainCashButton = new QPushButton(page_12);
        cancelObtainCashButton->setObjectName("cancelObtainCashButton");
        cancelObtainCashButton->setGeometry(QRect(0, 0, 71, 31));
        cancelObtainCashButton->setIcon(icon);
        obtainCashLineEdit = new QLineEdit(page_12);
        obtainCashLineEdit->setObjectName("obtainCashLineEdit");
        obtainCashLineEdit->setGeometry(QRect(180, 140, 113, 20));
        label_19 = new QLabel(page_12);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(70, 140, 100, 20));
        label_19->setFont(font4);
        stackedWidget->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName("page_13");
        label_20 = new QLabel(page_13);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(70, 160, 100, 20));
        label_20->setFont(font4);
        confirmTransferPushButton = new QPushButton(page_13);
        confirmTransferPushButton->setObjectName("confirmTransferPushButton");
        confirmTransferPushButton->setGeometry(QRect(210, 190, 80, 18));
        cancelTransferButton = new QPushButton(page_13);
        cancelTransferButton->setObjectName("cancelTransferButton");
        cancelTransferButton->setGeometry(QRect(0, 0, 71, 31));
        cancelTransferButton->setIcon(icon);
        transferLineEdit = new QLineEdit(page_13);
        transferLineEdit->setObjectName("transferLineEdit");
        transferLineEdit->setGeometry(QRect(180, 160, 113, 20));
        label_21 = new QLabel(page_13);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(110, 50, 180, 30));
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(page_13);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(70, 130, 100, 20));
        label_22->setFont(font4);
        transferCardLineEdit = new QLineEdit(page_13);
        transferCardLineEdit->setObjectName("transferCardLineEdit");
        transferCardLineEdit->setGeometry(QRect(180, 130, 113, 20));
        stackedWidget->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName("page_14");
        label_23 = new QLabel(page_14);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(50, 190, 100, 20));
        label_23->setFont(font4);
        label_24 = new QLabel(page_14);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 40, 380, 100));
        QFont font5;
        font5.setPointSize(10);
        label_24->setFont(font5);
        label_24->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(page_14);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(50, 160, 160, 20));
        label_25->setFont(font4);
        surfeitReceiverLineEdit = new QLineEdit(page_14);
        surfeitReceiverLineEdit->setObjectName("surfeitReceiverLineEdit");
        surfeitReceiverLineEdit->setGeometry(QRect(230, 160, 113, 20));
        maxBalanceLineEdit = new QLineEdit(page_14);
        maxBalanceLineEdit->setObjectName("maxBalanceLineEdit");
        maxBalanceLineEdit->setGeometry(QRect(230, 190, 113, 20));
        confirmSurfeitProcessingPushButton = new QPushButton(page_14);
        confirmSurfeitProcessingPushButton->setObjectName("confirmSurfeitProcessingPushButton");
        confirmSurfeitProcessingPushButton->setGeometry(QRect(260, 220, 80, 18));
        cancelSurfeitProcessingButton = new QPushButton(page_14);
        cancelSurfeitProcessingButton->setObjectName("cancelSurfeitProcessingButton");
        cancelSurfeitProcessingButton->setGeometry(QRect(0, 0, 71, 31));
        cancelSurfeitProcessingButton->setIcon(icon);
        stackedWidget->addWidget(page_14);
        page_15 = new QWidget();
        page_15->setObjectName("page_15");
        transferCardLineEdit_2 = new QLineEdit(page_15);
        transferCardLineEdit_2->setObjectName("transferCardLineEdit_2");
        transferCardLineEdit_2->setGeometry(QRect(200, 130, 113, 20));
        cancelTransferButton_2 = new QPushButton(page_15);
        cancelTransferButton_2->setObjectName("cancelTransferButton_2");
        cancelTransferButton_2->setGeometry(QRect(0, 0, 71, 31));
        cancelTransferButton_2->setIcon(icon);
        label_26 = new QLabel(page_15);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(110, 50, 180, 30));
        label_26->setFont(font);
        label_26->setAlignment(Qt::AlignCenter);
        confirmTransferPushButton_2 = new QPushButton(page_15);
        confirmTransferPushButton_2->setObjectName("confirmTransferPushButton_2");
        confirmTransferPushButton_2->setGeometry(QRect(230, 190, 80, 18));
        label_27 = new QLabel(page_15);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(49, 130, 141, 20));
        label_27->setFont(font4);
        stackedWidget->addWidget(page_15);
        TheWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TheWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 17));
        TheWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TheWindow);
        statusbar->setObjectName("statusbar");
        TheWindow->setStatusBar(statusbar);

        retranslateUi(TheWindow);

        stackedWidget->setCurrentIndex(8);
        stackedWidget_2->setCurrentIndex(1);
        stackedWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TheWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TheWindow)
    {
        TheWindow->setWindowTitle(QCoreApplication::translate("TheWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("TheWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("TheWindow", "Register", nullptr));
        label_3->setText(QCoreApplication::translate("TheWindow", "Account Number:", nullptr));
        label_4->setText(QCoreApplication::translate("TheWindow", "Account Pin-code:", nullptr));
        registerErrorLabel->setText(QCoreApplication::translate("TheWindow", "Incorrect number or pin", nullptr));
        label->setText(QCoreApplication::translate("TheWindow", "Checking Account", nullptr));
        balanceLabelC->setText(QCoreApplication::translate("TheWindow", "Balance: xxx", nullptr));
        obtainCashButtonC->setText(QCoreApplication::translate("TheWindow", "Obtain Cash", nullptr));
        putCashButtonC->setText(QCoreApplication::translate("TheWindow", "Put Cash", nullptr));
        transferButtonC->setText(QCoreApplication::translate("TheWindow", "Money transfer", nullptr));
        surfeitProcessingButton->setText(QCoreApplication::translate("TheWindow", "Money surfeit processing\n"
"service", nullptr));
        logOutButtonC->setText(QCoreApplication::translate("TheWindow", "Log out", nullptr));
        loginButton_2->setText(QCoreApplication::translate("TheWindow", "Login", nullptr));
        label_6->setText(QCoreApplication::translate("TheWindow", "Register", nullptr));
        label_7->setText(QCoreApplication::translate("TheWindow", "Account Number:", nullptr));
        label_8->setText(QCoreApplication::translate("TheWindow", "Account Pin-code:", nullptr));
        label_9->setText(QCoreApplication::translate("TheWindow", "Savings Account", nullptr));
        balanceLabelS->setText(QCoreApplication::translate("TheWindow", "Balance: xxx", nullptr));
        obtainCashButtonS->setText(QCoreApplication::translate("TheWindow", "Obtain Cash", nullptr));
        putCashButtonS->setText(QCoreApplication::translate("TheWindow", "Put Cash", nullptr));
        transferButtonS->setText(QCoreApplication::translate("TheWindow", "Money transfer", nullptr));
        logOutButtonS->setText(QCoreApplication::translate("TheWindow", "Log out", nullptr));
        loginButton_3->setText(QCoreApplication::translate("TheWindow", "Login", nullptr));
        label_11->setText(QCoreApplication::translate("TheWindow", "Register", nullptr));
        label_12->setText(QCoreApplication::translate("TheWindow", "Account Number:", nullptr));
        label_13->setText(QCoreApplication::translate("TheWindow", "Account Pin-code:", nullptr));
        label_14->setText(QCoreApplication::translate("TheWindow", "Line of Credit Account", nullptr));
        balanceLabelL->setText(QCoreApplication::translate("TheWindow", "Balance: xxx", nullptr));
        obtainCashButtonL->setText(QCoreApplication::translate("TheWindow", "Obtain Cash", nullptr));
        putCashButtonL->setText(QCoreApplication::translate("TheWindow", "Put Cash", nullptr));
        transferButtonL->setText(QCoreApplication::translate("TheWindow", "Money transfer", nullptr));
        pushButton_12->setText(QCoreApplication::translate("TheWindow", "Change backup card", nullptr));
        logOutButtonL->setText(QCoreApplication::translate("TheWindow", "Log out", nullptr));
        label_16->setText(QCoreApplication::translate("TheWindow", "Putting cash...", nullptr));
        cancelPutCashButton->setText(QString());
        label_17->setText(QCoreApplication::translate("TheWindow", "Enter sum:", nullptr));
        confirmPutCashPushButton->setText(QCoreApplication::translate("TheWindow", "Confirm", nullptr));
        confirmObtainCashPushButton->setText(QCoreApplication::translate("TheWindow", "Confirm", nullptr));
        label_18->setText(QCoreApplication::translate("TheWindow", "Obtaining cash...", nullptr));
        cancelObtainCashButton->setText(QString());
        label_19->setText(QCoreApplication::translate("TheWindow", "Enter sum:", nullptr));
        label_20->setText(QCoreApplication::translate("TheWindow", "Enter sum:", nullptr));
        confirmTransferPushButton->setText(QCoreApplication::translate("TheWindow", "Confirm", nullptr));
        cancelTransferButton->setText(QString());
        label_21->setText(QCoreApplication::translate("TheWindow", "Transfering money...", nullptr));
        label_22->setText(QCoreApplication::translate("TheWindow", "Transfer to:", nullptr));
        transferCardLineEdit->setPlaceholderText(QCoreApplication::translate("TheWindow", "xxxxxxxxxxxxxxxx", nullptr));
        label_23->setText(QCoreApplication::translate("TheWindow", "Threshold:", nullptr));
        label_24->setText(QCoreApplication::translate("TheWindow", "This service offers you the opportunity to\n"
"pick a card to receive excessive money.\n"
"If your balance on the current card exceeds\n"
" a certain threshold, the surfeit will be transfered to the card\n"
"you pick now.", nullptr));
        label_25->setText(QCoreApplication::translate("TheWindow", "Surfeit Receiver Card:", nullptr));
        surfeitReceiverLineEdit->setPlaceholderText(QCoreApplication::translate("TheWindow", "xxxxxxxxxxxxxxxx", nullptr));
        confirmSurfeitProcessingPushButton->setText(QCoreApplication::translate("TheWindow", "Confirm", nullptr));
        cancelSurfeitProcessingButton->setText(QString());
        transferCardLineEdit_2->setPlaceholderText(QCoreApplication::translate("TheWindow", "xxxxxxxxxxxxxxxx", nullptr));
        cancelTransferButton_2->setText(QString());
        label_26->setText(QCoreApplication::translate("TheWindow", "Changing backup card...", nullptr));
        confirmTransferPushButton_2->setText(QCoreApplication::translate("TheWindow", "Confirm", nullptr));
        label_27->setText(QCoreApplication::translate("TheWindow", "New Card Number:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TheWindow: public Ui_TheWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEWINDOW_H
