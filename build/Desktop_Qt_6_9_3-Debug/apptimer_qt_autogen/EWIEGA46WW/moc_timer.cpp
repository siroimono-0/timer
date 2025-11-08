/****************************************************************************
** Meta object code from reading C++ file 'timer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../timer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
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
struct qt_meta_tag_ZN5TimerE_t {};
} // unnamed namespace

template <> constexpr inline auto Timer::qt_create_metaobjectdata<qt_meta_tag_ZN5TimerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Timer",
        "QML.Element",
        "auto",
        "sig_qs_curDate",
        "",
        "sig_qs_curTime",
        "sig_p_cppModel",
        "sig_qs_medi",
        "sig_qs_mediDialog",
        "slot_timeout",
        "invok_addTimer",
        "qba",
        "invok_updateStat",
        "qml_idx",
        "invok_delete",
        "invok_mediFile",
        "invok_mediCheckText",
        "invok_mediNext",
        "qs_curDate",
        "qs_curTime",
        "p_cppModel",
        "CppModel*",
        "qs_medi",
        "qs_mediDialog"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sig_qs_curDate'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sig_qs_curTime'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sig_p_cppModel'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sig_qs_medi'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sig_qs_mediDialog'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_timeout'
        QtMocHelpers::SlotData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'invok_addTimer'
        QtMocHelpers::MethodData<void(QByteArray)>(10, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 11 },
        }}),
        // Method 'invok_updateStat'
        QtMocHelpers::MethodData<void(int)>(12, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Method 'invok_delete'
        QtMocHelpers::MethodData<void(int)>(14, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Method 'invok_mediFile'
        QtMocHelpers::MethodData<void()>(15, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'invok_mediCheckText'
        QtMocHelpers::MethodData<void()>(16, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'invok_mediNext'
        QtMocHelpers::MethodData<bool()>(17, 4, QMC::AccessPublic, QMetaType::Bool),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'qs_curDate'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Final, 0),
        // property 'qs_curTime'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Final, 1),
        // property 'p_cppModel'
        QtMocHelpers::PropertyData<CppModel*>(20, 0x80000000 | 21, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Final, 2),
        // property 'qs_medi'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Final, 3),
        // property 'qs_mediDialog'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Final, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<Timer, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Timer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5TimerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5TimerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5TimerE_t>.metaTypes,
    nullptr
} };

void Timer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Timer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sig_qs_curDate(); break;
        case 1: _t->sig_qs_curTime(); break;
        case 2: _t->sig_p_cppModel(); break;
        case 3: _t->sig_qs_medi(); break;
        case 4: _t->sig_qs_mediDialog(); break;
        case 5: _t->slot_timeout(); break;
        case 6: _t->invok_addTimer((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 7: _t->invok_updateStat((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->invok_delete((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->invok_mediFile(); break;
        case 10: _t->invok_mediCheckText(); break;
        case 11: { bool _r = _t->invok_mediNext();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Timer::*)()>(_a, &Timer::sig_qs_curDate, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Timer::*)()>(_a, &Timer::sig_qs_curTime, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Timer::*)()>(_a, &Timer::sig_p_cppModel, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Timer::*)()>(_a, &Timer::sig_qs_medi, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Timer::*)()>(_a, &Timer::sig_qs_mediDialog, 4))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CppModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->get_qs_curDate(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->get_qs_curTime(); break;
        case 2: *reinterpret_cast<CppModel**>(_v) = _t->get_p_cppModel(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->get_qs_medi(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->get_qs_mediDialog(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_qs_curDate(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->set_qs_curDate(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->set_qs_medi(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->set_qs_mediDialog(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Timer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Timer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5TimerE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QQmlParserStatus"))
        return static_cast< QQmlParserStatus*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QQmlParserStatus"))
        return static_cast< QQmlParserStatus*>(this);
    return QObject::qt_metacast(_clname);
}

int Timer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Timer::sig_qs_curDate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Timer::sig_qs_curTime()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Timer::sig_p_cppModel()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Timer::sig_qs_medi()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Timer::sig_qs_mediDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
