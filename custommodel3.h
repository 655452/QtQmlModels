#ifndef CUSTOMMODEL3_H
#define CUSTOMMODEL3_H

#include <QAbstractListModel>
#include <QVector>
#include <QDebug>

// Structure to define individual items in the model
struct Item3 {
    int id;
    QString description;
};

class CustomModel3 : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        DescriptionRole
    };

    explicit CustomModel3(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addEntry(int id, const QString &description);
    Q_INVOKABLE void removeEntry(int row);

private:
    QVector<Item3> m_entries; // Data container for model
};

#endif // CUSTOMMODEL3_H
