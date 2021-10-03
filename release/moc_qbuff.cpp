/****************************************************************************
** Meta object code from reading C++ file 'qbuff.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qbuff.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qbuff.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QBuff_t {
    QByteArrayData data[3];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QBuff_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QBuff_t qt_meta_stringdata_QBuff = {
    {
QT_MOC_LITERAL(0, 0, 5), // "QBuff"
QT_MOC_LITERAL(1, 6, 8), // "buffDead"
QT_MOC_LITERAL(2, 15, 0) // ""

    },
    "QBuff\0buffDead\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QBuff[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Int,

       0        // eod
};

void QBuff::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QBuff *_t = static_cast<QBuff *>(_o);
        switch (_id) {
        case 0: { int _r = _t->buffDead();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (QBuff::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QBuff::buffDead)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QBuff::staticMetaObject = {
    { &QGameElement::staticMetaObject, qt_meta_stringdata_QBuff.data,
      qt_meta_data_QBuff,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QBuff::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QBuff::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QBuff.stringdata))
        return static_cast<void*>(const_cast< QBuff*>(this));
    return QGameElement::qt_metacast(_clname);
}

int QBuff::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGameElement::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
int QBuff::buffDead()
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
