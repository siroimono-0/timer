#include "cppmodel.h"

CppModel::CppModel(QObject *parent)
    : QAbstractListModel{parent}
{
    return;
}

void CppModel::add_data(QString qs_insert)
{
    int row = this->vec_qs.size();
    QTime tmp_time(0, 0, 0, 0);
    this->vec_stat.push_back(true);

    beginInsertRows(QModelIndex(), row, row);
    this->vec_qs.push_back({qs_insert, tmp_time});
    endInsertRows();

    return;
}

void CppModel::update_timer()
{
    // qDebug() << " ?" << "\n";
    beginResetModel();
    for (int i = 0; i < this->vec_qs.size(); i++)
    {
        if (this->vec_stat[i] == true)
        {
            this->vec_qs[i].second = this->vec_qs[i].second.addSecs(1);
        }
    }
    endResetModel();
    return;
}

void CppModel::update_stat(int idx)
{
    this->vec_stat[idx] = !(this->vec_stat[idx]);
    return;
}

void CppModel::delete_timer(int idx)
{
    this->vec_stat.removeAt(idx);
    beginRemoveRows(QModelIndex(), idx, idx);
    this->vec_qs.removeAt(idx);
    endRemoveRows();

    return;
}

//=================================================================
int CppModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }
    return vec_qs.size();
}

QVariant CppModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= vec_qs.size())
    {
        return QVariant();
    }

    QString tmp_qs = vec_qs.at(index.row()).first;
    tmp_qs += " -> ";
    tmp_qs += vec_qs.at(index.row()).second.toString();

    if (role == TextRole)
    {
        return QVariant(tmp_qs);
    }
    else if (role == IndexRole)
    {
        return index.row();
    }

    return QVariant();
}

// QML에서 model.text로 접근할 수 있도록 role과 이름 매핑
QHash<int, QByteArray> CppModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TextRole] = "text";
    roles[IndexRole] = "index";
    return roles;
}
//=================================================================
