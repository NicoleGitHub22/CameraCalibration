/****************************************************************************
** Meta object code from reading C++ file 'renderer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Lightstage-Stage2/renderer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Renderer_t {
    QByteArrayData data[13];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Renderer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Renderer_t qt_meta_stringdata_Renderer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Renderer"
QT_MOC_LITERAL(1, 9, 9), // "newRender"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "rndr"
QT_MOC_LITERAL(4, 25, 9), // "newNormal"
QT_MOC_LITERAL(5, 35, 6), // "normal"
QT_MOC_LITERAL(6, 42, 10), // "newDiffuse"
QT_MOC_LITERAL(7, 53, 4), // "diff"
QT_MOC_LITERAL(8, 58, 7), // "newSpec"
QT_MOC_LITERAL(9, 66, 4), // "spec"
QT_MOC_LITERAL(10, 71, 8), // "newMixed"
QT_MOC_LITERAL(11, 80, 5), // "mixed"
QT_MOC_LITERAL(12, 86, 8) // "onRender"

    },
    "Renderer\0newRender\0\0rndr\0newNormal\0"
    "normal\0newDiffuse\0diff\0newSpec\0spec\0"
    "newMixed\0mixed\0onRender"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Renderer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       8,    1,   53,    2, 0x06 /* Public */,
      10,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void, QMetaType::QImage,    7,
    QMetaType::Void, QMetaType::QImage,    9,
    QMetaType::Void, QMetaType::QImage,   11,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Renderer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Renderer *_t = static_cast<Renderer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newRender((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->newNormal((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->newDiffuse((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->newSpec((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->newMixed((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->onRender(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Renderer::*_t)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Renderer::newRender)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Renderer::*_t)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Renderer::newNormal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Renderer::*_t)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Renderer::newDiffuse)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Renderer::*_t)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Renderer::newSpec)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Renderer::*_t)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Renderer::newMixed)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Renderer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Renderer.data,
      qt_meta_data_Renderer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Renderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Renderer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Renderer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Renderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Renderer::newRender(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Renderer::newNormal(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Renderer::newDiffuse(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Renderer::newSpec(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Renderer::newMixed(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
