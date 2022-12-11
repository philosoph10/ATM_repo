QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    #TestAccounts.cpp \
    clientbase.cpp \
    main.cpp \
    checkingaccount.cpp \
    savingsaccount.cpp \
    lineofcreditaccount.cpp \
    account.cpp \
    thewindow.cpp

HEADERS += \
    Account.h \
    CheckingAccount.h \
    LineOfCreditAccount.h \
    SavingsAccount.h \
    clientbase.h \
    thewindow.h

FORMS += \
    thewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    classdiagram.qmodel

QT += testlib

QT += widgets testlib

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../QT Console Apps/SimpleSmtp_SSL_QT5-master/build-smtp-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/release/' -lsmtp
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../QT Console Apps/SimpleSmtp_SSL_QT5-master/build-smtp-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/debug/' -lsmtp
#else:unix: LIBS += -L$$PWD/'../../../../QT Console Apps/SimpleSmtp_SSL_QT5-master/build-smtp-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/' -lsmtp

#INCLUDEPATH += $$PWD/'../../../../QT Console Apps/SimpleSmtp_SSL_QT5-master/build-smtp-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/debug'
#DEPENDPATH += $$PWD/'../../../../QT Console Apps/SimpleSmtp_SSL_QT5-master/build-smtp-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/debug'
