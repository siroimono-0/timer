#ifndef TIMER_H
#define TIMER_H

#include <QtQml/qqml.h>
#include <QtQml/qqmlparserstatus.h>
//=============================================
#include <QByteArray>
#include <QDate>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QTime>
#include <QTimer>
//=============================================
#include "cppmodel.h"

class Timer : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    QML_ELEMENT
    Q_INTERFACES(QQmlParserStatus) // 반드시 필요

    Q_PROPERTY(
        QString qs_curDate READ get_qs_curDate WRITE set_qs_curDate NOTIFY sig_qs_curDate FINAL)

    Q_PROPERTY(
        QString qs_curTime READ get_qs_curTime WRITE set_qs_curDate NOTIFY sig_qs_curTime FINAL)

    Q_PROPERTY(CppModel *p_cppModel READ get_p_cppModel NOTIFY sig_p_cppModel FINAL)

    Q_PROPERTY(QString qs_medi READ get_qs_medi WRITE set_qs_medi NOTIFY sig_qs_medi FINAL)

    Q_PROPERTY(QString qs_mediDialog READ get_qs_mediDialog WRITE set_qs_mediDialog NOTIFY
                   sig_qs_mediDialog FINAL)

public:
    explicit Timer(QObject *parent = nullptr);
    //=============================================

    void classBegin();
    void componentComplete();

    //=============================================

    void set_qs_curDate(QString curDate);
    QString get_qs_curDate();

    //=============================================

    void set_qs_curTime(QString curTime);
    QString get_qs_curTime();

    //=============================================

    CppModel *get_p_cppModel();

    //=============================================

    void set_qs_medi(QString qs);
    QString get_qs_medi();

    //=============================================

    void set_qs_mediDialog(QString qs);
    QString get_qs_mediDialog();

    //=============================================

    void fistSet_curTime();
    void fistSet_curTimer();
    void fistSet_p_cppModel();
    void fistSet_p_file();
    void fistSet_vec_qsMedi();

    //=============================================

    //=============================================
    Q_INVOKABLE void invok_addTimer(QByteArray qba);
    Q_INVOKABLE void invok_updateStat(int qml_idx);
    Q_INVOKABLE void invok_delete(int qml_idx);
    Q_INVOKABLE void invok_mediFile();
    Q_INVOKABLE void invok_mediCheckText();
    Q_INVOKABLE bool invok_mediNext();

    //=============================================

public slots:
    void slot_timeout();

signals:
    void sig_qs_curDate();
    void sig_qs_curTime();
    void sig_p_cppModel();
    void sig_qs_medi();
    void sig_qs_mediDialog();

private:
    QDate current_date;
    QTime current_time;
    QTimer curTimer;

    QString qs_curDate;
    QString qs_curTime;

    QFile *p_file;

    QString qs_medi = "Hello?";
    std::pair<int, bool> mediStat = {0, false};
    QVector<QString> vec_qsMedi;
    QString qs_mediDialog = "";

    CppModel *p_cppModel;
};

#endif // TIMER_H
