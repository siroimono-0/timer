#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "timer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Timer cpp_tmier;
    qmlRegisterType<Timer>("timer_qt", 1, 0, "Timer");
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("timer_qt", "Main");
    return app.exec();
}
