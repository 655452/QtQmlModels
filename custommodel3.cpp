#include "custommodel3.h"

// Constructor
CustomModel3::CustomModel3(QObject *parent) : QAbstractListModel(parent) {
    qDebug() << "CustomModel3 created.";
}

// Returns the number of rows in the model
int CustomModel3::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    return m_entries.size();
}

// Returns data for a given index and role
QVariant CustomModel3::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_entries.size())
        return QVariant();

    const Item3 &entry = m_entries.at(index.row());
    switch (role) {
    case IdRole:
        return entry.id;
    case DescriptionRole:
        return entry.description;
    default:
        return QVariant();
    }
}

// Defines the roles for the model
QHash<int, QByteArray> CustomModel3::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[DescriptionRole] = "description";
    return roles;
}

// Adds an entry to the model
void CustomModel3::addEntry(int id, const QString &description) {
    beginInsertRows(QModelIndex(), m_entries.size(), m_entries.size());
    m_entries.append({id, description});
    endInsertRows();
    qDebug() << "Entry added: ID=" << id << ", Description=" << description;
}

// Removes an entry from the model at a specific row
void CustomModel3::removeEntry(int row) {
    if (row < 0 || row >= m_entries.size())
        return;

    beginRemoveRows(QModelIndex(), row, row);
    m_entries.removeAt(row);
    endRemoveRows();
    qDebug() << "Entry removed at row:" << row;
}
