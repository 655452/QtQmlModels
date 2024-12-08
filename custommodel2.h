#ifndef CustomModel2_H
#define CustomModel2_H

#include <QAbstractListModel>
#include <QVector>
#include <QDebug>

struct Item2 {
    int id;
    QString name;
};

class CustomModel2 : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    explicit CustomModel2(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addItem(int id, const QString &name);
    Q_INVOKABLE void removeItem(int row);

private:
    QVector<Item2> m_items;
};

#endif // CustomModel2_H
