/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[24];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Server"
QT_MOC_LITERAL(1, 7, 13), // "newConnection"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "clientID"
QT_MOC_LITERAL(4, 31, 10), // "disconnect"
QT_MOC_LITERAL(5, 42, 10), // "calibrated"
QT_MOC_LITERAL(6, 53, 7), // "scanned"
QT_MOC_LITERAL(7, 61, 12), // "scanProgress"
QT_MOC_LITERAL(8, 74, 8), // "progress"
QT_MOC_LITERAL(9, 83, 10), // "scanFailed"
QT_MOC_LITERAL(10, 94, 8), // "errorMsg"
QT_MOC_LITERAL(11, 103, 9), // "calFailed"
QT_MOC_LITERAL(12, 113, 11), // "errorMsgCal"
QT_MOC_LITERAL(13, 125, 17), // "simpleStateUpdate"
QT_MOC_LITERAL(14, 143, 5), // "state"
QT_MOC_LITERAL(15, 149, 5), // "error"
QT_MOC_LITERAL(16, 155, 11), // "onCalibrate"
QT_MOC_LITERAL(17, 167, 6), // "onScan"
QT_MOC_LITERAL(18, 174, 16), // "maxLevelOfDetail"
QT_MOC_LITERAL(19, 191, 20), // "onClientDelayChanged"
QT_MOC_LITERAL(20, 212, 5), // "delay"
QT_MOC_LITERAL(21, 218, 15), // "onNewConnection"
QT_MOC_LITERAL(22, 234, 11), // "onReadyRead"
QT_MOC_LITERAL(23, 246, 12) // "onDisconnect"

    },
    "Server\0newConnection\0\0clientID\0"
    "disconnect\0calibrated\0scanned\0"
    "scanProgress\0progress\0scanFailed\0"
    "errorMsg\0calFailed\0errorMsgCal\0"
    "simpleStateUpdate\0state\0error\0onCalibrate\0"
    "onScan\0maxLevelOfDetail\0onClientDelayChanged\0"
    "delay\0onNewConnection\0onReadyRead\0"
    "onDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    0,   90,    2, 0x06 /* Public */,
       6,    0,   91,    2, 0x06 /* Public */,
       7,    1,   92,    2, 0x06 /* Public */,
       9,    1,   95,    2, 0x06 /* Public */,
      11,    1,   98,    2, 0x06 /* Public */,
      13,    2,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  106,    2, 0x0a /* Public */,
      17,    1,  107,    2, 0x0a /* Public */,
      19,    2,  110,    2, 0x0a /* Public */,
      21,    0,  115,    2, 0x08 /* Private */,
      22,    0,  116,    2, 0x08 /* Private */,
      23,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newConnection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->disconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->calibrated(); break;
        case 3: _t->scanned(); break;
        case 4: _t->scanProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->scanFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->calFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->simpleStateUpdate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->onCalibrate(); break;
        case 9: _t->onScan((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onClientDelayChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->onNewConnection(); break;
        case 12: _t->onReadyRead(); break;
        case 13: _t->onDisconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::newConnection)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::disconnect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::calibrated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::scanned)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::scanProgress)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Server::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::scanFailed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Server::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::calFailed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Server::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::simpleStateUpdate)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Server::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Server.data,
    qt_meta_data_Server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Server::newConnection(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::disconnect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::calibrated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Server::scanned()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Server::scanProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Server::scanFailed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Server::calFailed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Server::simpleStateUpdate(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
