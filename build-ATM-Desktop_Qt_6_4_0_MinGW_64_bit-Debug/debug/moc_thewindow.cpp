/****************************************************************************
** Meta object code from reading C++ file 'thewindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ATM/thewindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_TheWindow_t {
    uint offsetsAndSizes[32];
    char stringdata0[10];
    char stringdata1[14];
    char stringdata2[9];
    char stringdata3[1];
    char stringdata4[23];
    char stringdata5[14];
    char stringdata6[17];
    char stringdata7[20];
    char stringdata8[23];
    char stringdata9[27];
    char stringdata10[24];
    char stringdata11[18];
    char stringdata12[20];
    char stringdata13[15];
    char stringdata14[24];
    char stringdata15[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TheWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TheWindow_t qt_meta_stringdata_TheWindow = {
    {
        QT_MOC_LITERAL(0, 9),  // "TheWindow"
        QT_MOC_LITERAL(10, 13),  // "registerCheck"
        QT_MOC_LITERAL(24, 8),  // "Account*"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 22),  // "on_loginButton_clicked"
        QT_MOC_LITERAL(57, 13),  // "performLogout"
        QT_MOC_LITERAL(71, 16),  // "prepareToPutCash"
        QT_MOC_LITERAL(88, 19),  // "prepareToObtainCash"
        QT_MOC_LITERAL(108, 22),  // "prepareToTransferMoney"
        QT_MOC_LITERAL(131, 26),  // "prepareToSurfeitProcessing"
        QT_MOC_LITERAL(158, 23),  // "prepareToChangingBackup"
        QT_MOC_LITERAL(182, 17),  // "cancelPuttingCash"
        QT_MOC_LITERAL(200, 19),  // "cancelObtainingCash"
        QT_MOC_LITERAL(220, 14),  // "cancelTransfer"
        QT_MOC_LITERAL(235, 23),  // "cancelSurfeitProcessing"
        QT_MOC_LITERAL(259, 20)   // "cancelChangingBackup"
    },
    "TheWindow",
    "registerCheck",
    "Account*",
    "",
    "on_loginButton_clicked",
    "performLogout",
    "prepareToPutCash",
    "prepareToObtainCash",
    "prepareToTransferMoney",
    "prepareToSurfeitProcessing",
    "prepareToChangingBackup",
    "cancelPuttingCash",
    "cancelObtainingCash",
    "cancelTransfer",
    "cancelSurfeitProcessing",
    "cancelChangingBackup"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TheWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    3, 0x08,    1 /* Private */,
       4,    0,   93,    3, 0x08,    2 /* Private */,
       5,    0,   94,    3, 0x08,    3 /* Private */,
       6,    0,   95,    3, 0x08,    4 /* Private */,
       7,    0,   96,    3, 0x08,    5 /* Private */,
       8,    0,   97,    3, 0x08,    6 /* Private */,
       9,    0,   98,    3, 0x08,    7 /* Private */,
      10,    0,   99,    3, 0x08,    8 /* Private */,
      11,    0,  100,    3, 0x08,    9 /* Private */,
      12,    0,  101,    3, 0x08,   10 /* Private */,
      13,    0,  102,    3, 0x08,   11 /* Private */,
      14,    0,  103,    3, 0x08,   12 /* Private */,
      15,    0,  104,    3, 0x08,   13 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TheWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TheWindow.offsetsAndSizes,
    qt_meta_data_TheWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TheWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TheWindow, std::true_type>,
        // method 'registerCheck'
        QtPrivate::TypeAndForceComplete<Account *, std::false_type>,
        // method 'on_loginButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'performLogout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prepareToPutCash'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prepareToObtainCash'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prepareToTransferMoney'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prepareToSurfeitProcessing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prepareToChangingBackup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cancelPuttingCash'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cancelObtainingCash'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cancelTransfer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cancelSurfeitProcessing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cancelChangingBackup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TheWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TheWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { Account* _r = _t->registerCheck();
            if (_a[0]) *reinterpret_cast< Account**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_loginButton_clicked(); break;
        case 2: _t->performLogout(); break;
        case 3: _t->prepareToPutCash(); break;
        case 4: _t->prepareToObtainCash(); break;
        case 5: _t->prepareToTransferMoney(); break;
        case 6: _t->prepareToSurfeitProcessing(); break;
        case 7: _t->prepareToChangingBackup(); break;
        case 8: _t->cancelPuttingCash(); break;
        case 9: _t->cancelObtainingCash(); break;
        case 10: _t->cancelTransfer(); break;
        case 11: _t->cancelSurfeitProcessing(); break;
        case 12: _t->cancelChangingBackup(); break;
        default: ;
        }
    }
}

const QMetaObject *TheWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TheWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TheWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TheWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
