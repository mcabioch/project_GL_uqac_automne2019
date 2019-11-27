/****************************************************************************
** Meta object code from reading C++ file 'Api.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/Api.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Api.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Api_t {
    QByteArrayData data[36];
    char stringdata0[446];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Api_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Api_t qt_meta_stringdata_Api = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Api"
QT_MOC_LITERAL(1, 4, 10), // "auth_ended"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10), // "auth_error"
QT_MOC_LITERAL(4, 27, 12), // "signin_ended"
QT_MOC_LITERAL(5, 40, 12), // "signin_error"
QT_MOC_LITERAL(6, 53, 11), // "std::string"
QT_MOC_LITERAL(7, 65, 2), // "id"
QT_MOC_LITERAL(8, 68, 10), // "save_ended"
QT_MOC_LITERAL(9, 79, 10), // "save_error"
QT_MOC_LITERAL(10, 90, 17), // "saveMembers_ended"
QT_MOC_LITERAL(11, 108, 17), // "saveMembers_error"
QT_MOC_LITERAL(12, 126, 12), // "getAll_ended"
QT_MOC_LITERAL(13, 139, 7), // "Globals"
QT_MOC_LITERAL(14, 147, 7), // "globals"
QT_MOC_LITERAL(15, 155, 23), // "std::vector<TeamMember>"
QT_MOC_LITERAL(16, 179, 11), // "teamMembers"
QT_MOC_LITERAL(17, 191, 8), // "Planning"
QT_MOC_LITERAL(18, 200, 8), // "planning"
QT_MOC_LITERAL(19, 209, 12), // "getAll_error"
QT_MOC_LITERAL(20, 222, 13), // "compute_ended"
QT_MOC_LITERAL(21, 236, 13), // "compute_error"
QT_MOC_LITERAL(22, 250, 6), // "getAll"
QT_MOC_LITERAL(23, 257, 8), // "auth_end"
QT_MOC_LITERAL(24, 266, 14), // "QNetworkReply*"
QT_MOC_LITERAL(25, 281, 5), // "reply"
QT_MOC_LITERAL(26, 287, 12), // "register_end"
QT_MOC_LITERAL(27, 300, 8), // "save_end"
QT_MOC_LITERAL(28, 309, 15), // "saveMembers_end"
QT_MOC_LITERAL(29, 325, 10), // "getAll_end"
QT_MOC_LITERAL(30, 336, 11), // "compute_end"
QT_MOC_LITERAL(31, 348, 17), // "register_user_end"
QT_MOC_LITERAL(32, 366, 17), // "register_team_end"
QT_MOC_LITERAL(33, 384, 23), // "register_teammember_end"
QT_MOC_LITERAL(34, 408, 15), // "signin_user_end"
QT_MOC_LITERAL(35, 424, 21) // "signin_teammember_end"

    },
    "Api\0auth_ended\0\0auth_error\0signin_ended\0"
    "signin_error\0std::string\0id\0save_ended\0"
    "save_error\0saveMembers_ended\0"
    "saveMembers_error\0getAll_ended\0Globals\0"
    "globals\0std::vector<TeamMember>\0"
    "teamMembers\0Planning\0planning\0"
    "getAll_error\0compute_ended\0compute_error\0"
    "getAll\0auth_end\0QNetworkReply*\0reply\0"
    "register_end\0save_end\0saveMembers_end\0"
    "getAll_end\0compute_end\0register_user_end\0"
    "register_team_end\0register_teammember_end\0"
    "signin_user_end\0signin_teammember_end"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Api[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  149,    2, 0x06 /* Public */,
       3,    0,  150,    2, 0x06 /* Public */,
       4,    0,  151,    2, 0x06 /* Public */,
       5,    0,  152,    2, 0x06 /* Public */,
       4,    1,  153,    2, 0x06 /* Public */,
       5,    1,  156,    2, 0x06 /* Public */,
       8,    0,  159,    2, 0x06 /* Public */,
       9,    0,  160,    2, 0x06 /* Public */,
      10,    0,  161,    2, 0x06 /* Public */,
      11,    0,  162,    2, 0x06 /* Public */,
      12,    0,  163,    2, 0x06 /* Public */,
      12,    3,  164,    2, 0x06 /* Public */,
      19,    0,  171,    2, 0x06 /* Public */,
      20,    0,  172,    2, 0x06 /* Public */,
      21,    0,  173,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    0,  174,    2, 0x0a /* Public */,
      23,    1,  175,    2, 0x0a /* Public */,
      26,    1,  178,    2, 0x0a /* Public */,
      27,    1,  181,    2, 0x0a /* Public */,
      28,    1,  184,    2, 0x0a /* Public */,
      29,    1,  187,    2, 0x0a /* Public */,
      30,    1,  190,    2, 0x0a /* Public */,
      31,    1,  193,    2, 0x0a /* Public */,
      32,    1,  196,    2, 0x0a /* Public */,
      33,    1,  199,    2, 0x0a /* Public */,
      34,    1,  202,    2, 0x0a /* Public */,
      35,    1,  205,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15, 0x80000000 | 17,   14,   16,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,

       0        // eod
};

void Api::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Api *_t = static_cast<Api *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->auth_ended(); break;
        case 1: _t->auth_error(); break;
        case 2: _t->signin_ended(); break;
        case 3: _t->signin_error(); break;
        case 4: _t->signin_ended((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 5: _t->signin_error((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 6: _t->save_ended(); break;
        case 7: _t->save_error(); break;
        case 8: _t->saveMembers_ended(); break;
        case 9: _t->saveMembers_error(); break;
        case 10: _t->getAll_ended(); break;
        case 11: _t->getAll_ended((*reinterpret_cast< const Globals(*)>(_a[1])),(*reinterpret_cast< const std::vector<TeamMember>(*)>(_a[2])),(*reinterpret_cast< const Planning(*)>(_a[3]))); break;
        case 12: _t->getAll_error(); break;
        case 13: _t->compute_ended(); break;
        case 14: _t->compute_error(); break;
        case 15: _t->getAll(); break;
        case 16: _t->auth_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 17: _t->register_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 18: _t->save_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 19: _t->saveMembers_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 20: _t->getAll_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 21: _t->compute_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 22: _t->register_user_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 23: _t->register_team_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 24: _t->register_teammember_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 25: _t->signin_user_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 26: _t->signin_teammember_end((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::auth_ended)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::auth_error)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::signin_ended)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::signin_error)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Api::*_t)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::signin_ended)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Api::*_t)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::signin_error)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::save_ended)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::save_error)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::saveMembers_ended)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::saveMembers_error)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::getAll_ended)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (Api::*_t)(const Globals & , const std::vector<TeamMember> & , const Planning & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::getAll_ended)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::getAll_error)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::compute_ended)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (Api::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Api::compute_error)) {
                *result = 14;
                return;
            }
        }
    }
}

const QMetaObject Api::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Api.data,
      qt_meta_data_Api,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Api::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Api::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Api.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Api::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void Api::auth_ended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Api::auth_error()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Api::signin_ended()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Api::signin_error()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Api::signin_ended(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Api::signin_error(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Api::save_ended()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Api::save_error()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Api::saveMembers_ended()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Api::saveMembers_error()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Api::getAll_ended()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Api::getAll_ended(const Globals & _t1, const std::vector<TeamMember> & _t2, const Planning & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Api::getAll_error()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void Api::compute_ended()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void Api::compute_error()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
