#ifndef CPPMODEL_H
#define CPPMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QTime>
#include <QtQml/qqml.h>
#include <QtQml/qqmlparserstatus.h>

// QML에서 사용할 리스트 모델 클래스 정의
class CppModel : public QAbstractListModel, public QQmlParserStatus
{
    Q_OBJECT // 시그널, 슬롯, QML 연동 기능 활성화
    QML_ELEMENT
    Q_INTERFACES(QQmlParserStatus) // 반드시 필요

public:
    //=================================================================
    enum Role {
        TextRole = Qt::UserRole + 1, // 사용자 정의 역할은 UserRole + 1부터 시작
        IndexRole = Qt::UserRole + 2
    };
    Q_ENUM(Role) // QML에서도 enum을 인식할 수 있게 함

    explicit CppModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    void classBegin() { return; }
    void componentComplete() { return; }
    //=================================================================

    void add_data(QString qs_insert);
    void update_timer();
    void update_stat(int idx);
    void delete_timer(int idx);

private:
    QVector<std::pair<QString, QTime>> vec_qs;
    QVector<bool> vec_stat;
};

#endif // CPPMODEL_H
