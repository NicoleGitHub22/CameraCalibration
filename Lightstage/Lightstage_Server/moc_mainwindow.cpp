/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "calibrate"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "scan"
QT_MOC_LITERAL(4, 27, 13), // "levelOfDetail"
QT_MOC_LITERAL(5, 41, 14), // "setClientDelay"
QT_MOC_LITERAL(6, 56, 5), // "delay"
QT_MOC_LITERAL(7, 62, 8), // "clientID"
QT_MOC_LITERAL(8, 71, 18), // "on_scanBtn_clicked"
QT_MOC_LITERAL(9, 90, 17), // "on_calBtn_clicked"
QT_MOC_LITERAL(10, 108, 38), // "on_delayClient0spinBox_editin..."
QT_MOC_LITERAL(11, 147, 38), // "on_delayClient1spinBox_editin..."
QT_MOC_LITERAL(12, 186, 22), // "on_stop_button_clicked"
QT_MOC_LITERAL(13, 209, 19), // "onSimpleStateUpdate"
QT_MOC_LITERAL(14, 229, 5), // "state"
QT_MOC_LITERAL(15, 235, 5), // "error"
QT_MOC_LITERAL(16, 241, 12), // "onCalibrated"
QT_MOC_LITERAL(17, 254, 9), // "onScanned"
QT_MOC_LITERAL(18, 264, 19), // "onCalibrationFailed"
QT_MOC_LITERAL(19, 284, 11), // "errorMsgCal"
QT_MOC_LITERAL(20, 296, 12), // "onScanFailed"
QT_MOC_LITERAL(21, 309, 8), // "errorMsg"
QT_MOC_LITERAL(22, 318, 15), // "onNewConnection"
QT_MOC_LITERAL(23, 334, 12), // "onDisconnect"
QT_MOC_LITERAL(24, 347, 14), // "onScanProgress"
QT_MOC_LITERAL(25, 362, 8) // "progress"

    },
    "MainWindow\0calibrate\0\0scan\0levelOfDetail\0"
    "setClientDelay\0delay\0clientID\0"
    "on_scanBtn_clicked\0on_calBtn_clicked\0"
    "on_delayClient0spinBox_editingFinished\0"
    "on_delayClient1spinBox_editingFinished\0"
    "on_stop_button_clicked\0onSimpleStateUpdate\0"
    "state\0error\0onCalibrated\0onScanned\0"
    "onCalibrationFailed\0errorMsgCal\0"
    "onScanFailed\0errorMsg\0onNewConnection\0"
    "onDisconnect\0onScanProgress\0progress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    1,  100,    2, 0x06 /* Public */,
       3,    0,  103,    2, 0x26 /* Public | MethodCloned */,
       5,    2,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  109,    2, 0x08 /* Private */,
       9,    0,  110,    2, 0x08 /* Private */,
      10,    0,  111,    2, 0x08 /* Private */,
      11,    0,  112,    2, 0x08 /* Private */,
      12,    0,  113,    2, 0x08 /* Private */,
      13,    2,  114,    2, 0x0a /* Public */,
      16,    0,  119,    2, 0x0a /* Public */,
      17,    0,  120,    2, 0x0a /* Public */,
      18,    1,  121,    2, 0x0a /* Public */,
      20,    1,  124,    2, 0x0a /* Public */,
      22,    1,  127,    2, 0x0a /* Public */,
      23,    1,  130,    2, 0x0a /* Public */,
      24,    1,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->calibrate(); break;
        case 1: _t->scan((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->scan(); break;
        case 3: _t->setClientDelay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_scanBtn_clicked(); break;
        case 5: _t->on_calBtn_clicked(); break;
        case 6: _t->on_delayClient0spinBox_editingFinished(); break;
        case 7: _t->on_delayClient1spinBox_editingFinished(); break;
        case 8: _t->on_stop_button_clicked(); break;
        case 9: _t->onSimpleStateUpdate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->onCalibrated(); break;
        case 11: _t->onScanned(); break;
        case 12: _t->onCalibrationFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->onScanFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->onNewConnection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->onDisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->onScanProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::calibrate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::scan)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setClientDelay)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::calibrate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::scan(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void MainWindow::setClientDelay(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
