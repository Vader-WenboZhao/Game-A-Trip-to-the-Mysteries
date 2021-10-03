/****************************************************************************
** Meta object code from reading C++ file 'qfairy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qfairy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfairy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QFairy_t {
    QByteArrayData data[12];
    char stringdata[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QFairy_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QFairy_t qt_meta_stringdata_QFairy = {
    {
QT_MOC_LITERAL(0, 0, 6), // "QFairy"
QT_MOC_LITERAL(1, 7, 8), // "addMyIce"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 10), // "destroyAll"
QT_MOC_LITERAL(4, 28, 12), // "addmanyscore"
QT_MOC_LITERAL(5, 41, 9), // "fairyDead"
QT_MOC_LITERAL(6, 51, 11), // "fairyStrong"
QT_MOC_LITERAL(7, 63, 15), // "buffDestroyDead"
QT_MOC_LITERAL(8, 79, 13), // "buffInvcbDead"
QT_MOC_LITERAL(9, 93, 16), // "buffAddScoreDead"
QT_MOC_LITERAL(10, 110, 11), // "buffIceDead"
QT_MOC_LITERAL(11, 122, 8) // "fairyfly"

    },
    "QFairy\0addMyIce\0\0destroyAll\0addmanyscore\0"
    "fairyDead\0fairyStrong\0buffDestroyDead\0"
    "buffInvcbDead\0buffAddScoreDead\0"
    "buffIceDead\0fairyfly"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QFairy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,
      11,    0,   73,    2, 0x06 /* Public */,

 // signals: parameters
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

void QFairy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QFairy *_t = static_cast<QFairy *>(_o);
        switch (_id) {
        case 0: _t->addMyIce(); break;
        case 1: _t->destroyAll(); break;
        case 2: _t->addmanyscore(); break;
        case 3: _t->fairyDead(); break;
        case 4: _t->fairyStrong(); break;
        case 5: _t->buffDestroyDead(); break;
        case 6: _t->buffInvcbDead(); break;
        case 7: _t->buffAddScoreDead(); break;
        case 8: _t->buffIceDead(); break;
        case 9: _t->fairyfly(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::addMyIce)) {
                *result = 0;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::destroyAll)) {
                *result = 1;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::addmanyscore)) {
                *result = 2;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::fairyDead)) {
                *result = 3;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::fairyStrong)) {
                *result = 4;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::buffDestroyDead)) {
                *result = 5;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::buffInvcbDead)) {
                *result = 6;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::buffAddScoreDead)) {
                *result = 7;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::buffIceDead)) {
                *result = 8;
            }
        }
        {
            typedef void (QFairy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFairy::fairyfly)) {
                *result = 9;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QFairy::staticMetaObject = {
    { &QGameElement::staticMetaObject, qt_meta_stringdata_QFairy.data,
      qt_meta_data_QFairy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QFairy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFairy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QFairy.stringdata))
        return static_cast<void*>(const_cast< QFairy*>(this));
    return QGameElement::qt_metacast(_clname);
}

int QFairy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGameElement::qt_metacall(_c, _id, _a);
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
void QFairy::addMyIce()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QFairy::destroyAll()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QFairy::addmanyscore()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QFairy::fairyDead()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void QFairy::fairyStrong()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void QFairy::buffDestroyDead()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void QFairy::buffInvcbDead()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void QFairy::buffAddScoreDead()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void QFairy::buffIceDead()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void QFairy::fairyfly()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
