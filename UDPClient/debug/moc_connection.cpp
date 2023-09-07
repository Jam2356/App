/****************************************************************************
** Meta object code from reading C++ file 'connection.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../connection.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_Connection_t {};
static constexpr auto qt_meta_stringdata_Connection = QtMocHelpers::stringData(
    "Connection",
    "datagramToInterface",
    "",
    "connectSetBlock",
    "connectWait",
    "QHostAddress",
    "addr",
    "port",
    "sendWait",
    "datagram",
    "disconnectWait",
    "incomingConnection"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_Connection_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[12];
    char stringdata5[13];
    char stringdata6[5];
    char stringdata7[5];
    char stringdata8[9];
    char stringdata9[9];
    char stringdata10[15];
    char stringdata11[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Connection_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Connection_t qt_meta_stringdata_Connection = {
    {
        QT_MOC_LITERAL(0, 10),  // "Connection"
        QT_MOC_LITERAL(11, 19),  // "datagramToInterface"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 15),  // "connectSetBlock"
        QT_MOC_LITERAL(48, 11),  // "connectWait"
        QT_MOC_LITERAL(60, 12),  // "QHostAddress"
        QT_MOC_LITERAL(73, 4),  // "addr"
        QT_MOC_LITERAL(78, 4),  // "port"
        QT_MOC_LITERAL(83, 8),  // "sendWait"
        QT_MOC_LITERAL(92, 8),  // "datagram"
        QT_MOC_LITERAL(101, 14),  // "disconnectWait"
        QT_MOC_LITERAL(116, 18)   // "incomingConnection"
    },
    "Connection",
    "datagramToInterface",
    "",
    "connectSetBlock",
    "connectWait",
    "QHostAddress",
    "addr",
    "port",
    "sendWait",
    "datagram",
    "disconnectWait",
    "incomingConnection"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Connection[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       3,    0,   53,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   54,    2, 0x08,    4 /* Private */,
       8,    1,   59,    2, 0x08,    7 /* Private */,
      10,    0,   62,    2, 0x08,    9 /* Private */,
      11,    0,   63,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::UShort,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

Q_CONSTINIT const QMetaObject Connection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Connection.offsetsAndSizes,
    qt_meta_data_Connection,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Connection_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Connection, std::true_type>,
        // method 'datagramToInterface'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'connectSetBlock'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectWait'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'sendWait'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'disconnectWait'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'incomingConnection'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Connection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->datagramToInterface((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->connectSetBlock(); break;
        case 2: _t->connectWait((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 3: _t->sendWait((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->disconnectWait(); break;
        case 5: { QString _r = _t->incomingConnection();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Connection::*)(QString );
            if (_t _q_method = &Connection::datagramToInterface; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Connection::*)();
            if (_t _q_method = &Connection::connectSetBlock; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Connection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Connection::datagramToInterface(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connection::connectSetBlock()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
