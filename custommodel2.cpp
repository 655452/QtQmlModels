#include "custommodel2.h"

CustomModel2::CustomModel2(QObject *parent) : QAbstractListModel(parent) {
    qDebug() << "Constructor has been  called custom model2";
}

int CustomModel2::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    return m_items.size();
}

QVariant CustomModel2::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_items.size())
        return QVariant();

    const Item2 &item = m_items.at(index.row());
    switch (role) {
    case IdRole:
        return item.id;
    case NameRole:
        return item.name;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> CustomModel2::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    return roles;
}

void CustomModel2::addItem(int id, const QString &name) {
    beginInsertRows(QModelIndex(), m_items.size(), m_items.size());
    m_items.append({id, name});
    endInsertRows();
    qDebug() << "Added item: id=" << id << ", name=" << name;
}

void CustomModel2::removeItem(int row) {
    if (row < 0 || row >= m_items.size())
        return;

    qDebug() << "Removed item at row: calleed"  ;
    beginRemoveRows(QModelIndex(), row, row);
    m_items.removeAt(row);
    endRemoveRows();
    qDebug() << "Removed item at row:" << row;
}
