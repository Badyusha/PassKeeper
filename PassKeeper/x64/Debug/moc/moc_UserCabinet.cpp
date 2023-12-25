/****************************************************************************
** Meta object code from reading C++ file 'UserCabinet.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../UserCabinet.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserCabinet.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSUserCabinetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSUserCabinetENDCLASS = QtMocHelpers::stringData(
    "UserCabinet",
    "on_actionQuit_triggered",
    "",
    "on_actionDeleteAccount_triggered",
    "on_actionCreate_new_triggered",
    "on_actionModify_triggered",
    "onButtonClicked",
    "WARNING_MESSAGE",
    "buttonId"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUserCabinetENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[33];
    char stringdata4[30];
    char stringdata5[26];
    char stringdata6[16];
    char stringdata7[16];
    char stringdata8[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUserCabinetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUserCabinetENDCLASS_t qt_meta_stringdata_CLASSUserCabinetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "UserCabinet"
        QT_MOC_LITERAL(12, 23),  // "on_actionQuit_triggered"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 32),  // "on_actionDeleteAccount_triggered"
        QT_MOC_LITERAL(70, 29),  // "on_actionCreate_new_triggered"
        QT_MOC_LITERAL(100, 25),  // "on_actionModify_triggered"
        QT_MOC_LITERAL(126, 15),  // "onButtonClicked"
        QT_MOC_LITERAL(142, 15),  // "WARNING_MESSAGE"
        QT_MOC_LITERAL(158, 8)   // "buttonId"
    },
    "UserCabinet",
    "on_actionQuit_triggered",
    "",
    "on_actionDeleteAccount_triggered",
    "on_actionCreate_new_triggered",
    "on_actionModify_triggered",
    "onButtonClicked",
    "WARNING_MESSAGE",
    "buttonId"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserCabinetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    1,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject UserCabinet::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserCabinetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserCabinetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserCabinetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserCabinet, std::true_type>,
        // method 'on_actionQuit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionDeleteAccount_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCreate_new_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionModify_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const WARNING_MESSAGE &, std::false_type>
    >,
    nullptr
} };

void UserCabinet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserCabinet *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionQuit_triggered(); break;
        case 1: _t->on_actionDeleteAccount_triggered(); break;
        case 2: _t->on_actionCreate_new_triggered(); break;
        case 3: _t->on_actionModify_triggered(); break;
        case 4: _t->onButtonClicked((*reinterpret_cast< std::add_pointer_t<WARNING_MESSAGE>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *UserCabinet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserCabinet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserCabinetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UserCabinet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
