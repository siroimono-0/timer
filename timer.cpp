#include "timer.h"

Timer::Timer(QObject *parent)
    : QObject{parent}
{
    return;
}

void Timer::classBegin()
{
    this->fistSet_curTime();
    this->fistSet_curTimer();
    this->fistSet_p_cppModel();
    this->fistSet_p_file();
    this->fistSet_vec_qsMedi();
    return;
}

void Timer::componentComplete()
{
    return;
}

void Timer::fistSet_vec_qsMedi()
{
    QString tmp_qs1 = "Silymarin \n"
                      "MSM \n"
                      "Vitamin C \n"
                      "Omega3 \n"
                      "Saw Palmetto\n"
                      "Lutein - Zeaxanthin \n"
                      "Astaxanthin \n";

    QString tmp_qs2 = "NMN \n"
                      "Alpha Lipoic Acid \n"
                      "Vitamin C \n"
                      "MSM \n"
                      "Omega3 \n"
                      "Saw Palmetto\n"
                      "Lutein - Zeaxanthin \n"
                      "Astaxanthin \n";

    QString tmp_qs3 = "NAC \n"
                      "MSM \n"
                      "Vitamin C \n"
                      "Chondroitin \n"
                      "Omega3 \n"
                      "Saw Palmetto\n"
                      "Lutein - Zeaxanthin \n"
                      "Astaxanthin \n";

    vec_qsMedi.push_back(tmp_qs1);
    vec_qsMedi.push_back(tmp_qs2);
    vec_qsMedi.push_back(tmp_qs3);
    return;
}
void Timer::fistSet_p_file()
{
    this->p_file = new QFile("medi.txt", this);
    this->p_file->open(QIODevice::OpenModeFlag::ReadWrite);
    if (!this->p_file->isOpen())
    {
        qDebug() << "File Open Err";
        return;
    }
    qDebug() << "Open" << "\n";
    return;
}

void Timer::fistSet_curTime()
{
    this->current_date = QDate::currentDate();
    this->current_time = QTime::currentTime();
    this->qs_curDate = this->current_date.toString();
    this->set_qs_curDate(this->qs_curDate);
    return;
}

void Timer::fistSet_p_cppModel()
{
    this->p_cppModel = new CppModel(this);
    this->p_cppModel->add_data("hello?");
    return;
}

void Timer::set_qs_curDate(QString curDate)
{
    this->qs_curDate = curDate;
    emit this->sig_qs_curDate();
    return;
}

QString Timer::get_qs_curDate()
{
    return this->qs_curDate;
}

CppModel *Timer::get_p_cppModel()
{
    return this->p_cppModel;
}

void Timer::fistSet_curTimer()
{
    connect(&this->curTimer, &QTimer::timeout, this, &Timer::slot_timeout);
    this->curTimer.setInterval(1000);
    this->curTimer.start(1000);
    return;
}

void Timer::slot_timeout()
{
    // qDebug() << this->current_time.currentTime().toString("hh:mm:ss");
    this->set_qs_curTime(this->current_time.currentTime().toString("hh:mm:ss"));

    this->p_cppModel->update_timer();
    return;
}

void Timer::set_qs_curTime(QString curTime)
{
    this->qs_curTime = curTime;
    emit this->sig_qs_curTime();
    return;
}

QString Timer::get_qs_curTime()
{
    return this->qs_curTime;
}

Q_INVOKABLE void Timer::invok_addTimer(QByteArray qba)
{
    if (qba.isEmpty())
    {
        qDebug() << "empty" << "\n";
    }

    this->p_cppModel->add_data(QString::fromUtf8(qba));
    return;
}

Q_INVOKABLE void Timer::invok_updateStat(int qml_idx)
{
    this->p_cppModel->update_stat(qml_idx);
    return;
}

Q_INVOKABLE void Timer::invok_delete(int qml_idx)
{
    this->p_cppModel->delete_timer(qml_idx);
    return;
}

void Timer::invok_mediFile()
{
    if (this->mediStat.second == true)
    {
        return;
    }

    int flag_medi = 0;
    QByteArray qba_buf;
    qba_buf = this->p_file->readAll();
    int tmp_size = qba_buf.size();

    if (qba_buf.isEmpty())
    {
        QByteArray qba_buf_write = "0";
        this->p_file->write(qba_buf_write);

        QString tmp_qs = "Day 0";
        this->set_qs_medi(tmp_qs);

        flag_medi = 0;
    }
    else
    {
        if (qba_buf.at(tmp_size - 1) == QByteArray("0"))
        {
            QByteArray qba_buf_write = "1";
            this->p_file->write(qba_buf_write);

            QString tmp_qs = "Day 1";
            this->set_qs_medi(tmp_qs);

            flag_medi = 1;
        }
        else if (qba_buf.at(tmp_size - 1) == QByteArray("1"))
        {
            QByteArray qba_buf_write = "2";
            this->p_file->write(qba_buf_write);

            QString tmp_qs = "Day 2";
            this->set_qs_medi(tmp_qs);

            flag_medi = 2;
        }
        else if (qba_buf.at(tmp_size - 1) == QByteArray("2"))
        {
            QByteArray qba_buf_write = "0";
            this->p_file->write(qba_buf_write);

            QString tmp_qs = "Day 0";
            this->set_qs_medi(tmp_qs);

            flag_medi = 0;
        }
    }

    this->mediStat = {flag_medi, true};

    return;
}

Q_INVOKABLE void Timer::invok_mediCheckText()
{
    if (this->qs_medi == this->qs_medi && this->qs_medi == "Day 0")
    {
        this->set_qs_mediDialog(this->vec_qsMedi[0]);
    }
    else if (this->qs_medi == this->qs_medi && this->qs_medi == "Day 1")
    {
        this->set_qs_mediDialog(this->vec_qsMedi[1]);
    }
    else if (this->qs_medi == this->qs_medi && this->qs_medi == "Day 2")
    {
        this->set_qs_mediDialog(this->vec_qsMedi[2]);
    }
    return;
}

void Timer::set_qs_medi(QString qs)
{
    this->qs_medi = qs;
    emit this->sig_qs_medi();
    return;
}

QString Timer::get_qs_medi()
{
    return this->qs_medi;
}

void Timer::set_qs_mediDialog(QString qs)
{
    this->qs_mediDialog = qs;
    emit this->sig_qs_mediDialog();
    return;
}

QString Timer::get_qs_mediDialog()
{
    return this->qs_mediDialog;
}

Q_INVOKABLE bool Timer::invok_mediNext()
{
    if(this->qs_medi == "Hello?")
    {
        return false;
    }

    if(this->qs_medi == "Day 0")
    {
        this->set_qs_medi("Day 1");
        this->set_qs_mediDialog(this->vec_qsMedi[1]);

        QByteArray qba_buf_write = "1";
        this->p_file->write(qba_buf_write);
    }
    else if(this->qs_medi == "Day 1")
    {
        this->set_qs_medi("Day 2");
        this->set_qs_mediDialog(this->vec_qsMedi[2]);

        QByteArray qba_buf_write = "2";
        this->p_file->write(qba_buf_write);
    }
    else if(this->qs_medi == "Day 2")
    {
        this->set_qs_medi("Day 0");
        this->set_qs_mediDialog(this->vec_qsMedi[0]);

        QByteArray qba_buf_write = "0";
        this->p_file->write(qba_buf_write);
    }

    return true;
}

