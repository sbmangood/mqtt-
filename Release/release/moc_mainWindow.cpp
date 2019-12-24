/****************************************************************************
** Meta object code from reading C++ file 'mainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zjMqttTool/mainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainWindow_t {
    QByteArrayData data[15];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainWindow_t qt_meta_stringdata_mainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainWindow"
QT_MOC_LITERAL(1, 11, 11), // "connectMqtt"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "mqttStruct"
QT_MOC_LITERAL(4, 35, 14), // "disConnectMqtt"
QT_MOC_LITERAL(5, 50, 7), // "pubMqtt"
QT_MOC_LITERAL(6, 58, 13), // "mqttPubStruct"
QT_MOC_LITERAL(7, 72, 7), // "subMqtt"
QT_MOC_LITERAL(8, 80, 21), // "updateBrowserMainText"
QT_MOC_LITERAL(9, 102, 3), // "str"
QT_MOC_LITERAL(10, 106, 20), // "clickedConnectButton"
QT_MOC_LITERAL(11, 127, 17), // "clickedSendButton"
QT_MOC_LITERAL(12, 145, 13), // "clickedAddSub"
QT_MOC_LITERAL(13, 159, 20), // "clickedClearSendText"
QT_MOC_LITERAL(14, 180, 20) // "clickedClearMainText"

    },
    "mainWindow\0connectMqtt\0\0mqttStruct\0"
    "disConnectMqtt\0pubMqtt\0mqttPubStruct\0"
    "subMqtt\0updateBrowserMainText\0str\0"
    "clickedConnectButton\0clickedSendButton\0"
    "clickedAddSub\0clickedClearSendText\0"
    "clickedClearMainText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       7,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   74,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainWindow *_t = static_cast<mainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectMqtt((*reinterpret_cast< mqttStruct(*)>(_a[1]))); break;
        case 1: _t->disConnectMqtt(); break;
        case 2: _t->pubMqtt((*reinterpret_cast< mqttPubStruct(*)>(_a[1]))); break;
        case 3: _t->subMqtt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->updateBrowserMainText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->clickedConnectButton(); break;
        case 6: _t->clickedSendButton(); break;
        case 7: _t->clickedAddSub(); break;
        case 8: _t->clickedClearSendText(); break;
        case 9: _t->clickedClearMainText(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (mainWindow::*_t)(mqttStruct );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainWindow::connectMqtt)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (mainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainWindow::disConnectMqtt)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (mainWindow::*_t)(mqttPubStruct );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainWindow::pubMqtt)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (mainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainWindow::subMqtt)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainWindow.data,
      qt_meta_data_mainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void mainWindow::connectMqtt(mqttStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mainWindow::disConnectMqtt()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void mainWindow::pubMqtt(mqttPubStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void mainWindow::subMqtt(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
