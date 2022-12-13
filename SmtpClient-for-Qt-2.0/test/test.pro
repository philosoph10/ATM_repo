#-------------------------------------------------
#
# Project created by QtCreator 2012-09-22T16:39:45
#
#-------------------------------------------------

QT       += testlib
QT       -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    connectiontest.cpp

HEADERS += \
    connectiontest.h

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../bin/lib/release/ -lSmtpMime
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../bin/lib/debug/ -lSmtpMime
#else:unix:!symbian: LIBS += -L$$PWD/../bin/lib/release/ -lSmtpMime

#INCLUDEPATH += $$PWD/../bin/lib/release
#DEPENDPATH += $$PWD/../bin/lib/release

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-SMTPEmail-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/release/ -lSmtpMime2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-SMTPEmail-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/debug/ -lSmtpMime2
else:unix: LIBS += -L$$PWD/../build-SMTPEmail-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/ -lSmtpMime2

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
