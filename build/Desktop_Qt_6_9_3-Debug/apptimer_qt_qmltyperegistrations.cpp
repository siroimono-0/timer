/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<cppmodel.h>)
#  include <cppmodel.h>
#endif
#if __has_include(<timer.h>)
#  include <timer.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_timer_qt()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<CppModel>("timer_qt", 1);
    qmlRegisterAnonymousType<QAbstractItemModel, 254>("timer_qt", 1);
    qmlRegisterEnum<CppModel::Role>("CppModel::Role");
    qmlRegisterTypesAndRevisions<Timer>("timer_qt", 1);
    QT_WARNING_POP
    qmlRegisterModule("timer_qt", 1, 0);
}

static const QQmlModuleRegistration timerqtRegistration("timer_qt", qml_register_types_timer_qt);
