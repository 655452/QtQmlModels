#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include <QDebug>

struct Item {
    int id;
    QString name;
};

class CustomModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    explicit CustomModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addItem(int id, const QString &name);
    Q_INVOKABLE void removeItem(int row);

private:
    QVector<Item> m_items;
};

#endif // CUSTOMMODEL_H
