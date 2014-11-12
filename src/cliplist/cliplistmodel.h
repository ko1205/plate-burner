#ifndef CLIPLISTMODEL_H
#define CLIPLISTMODEL_H

#include <QAbstractTableModel>
#include <QVector>

typedef struct _clipinfo{
    QString filepath;
    QString filename;
    int start;
    int end;
    int duration;
    QVector<int> missingframe;
} clipinfo;

class ClipListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ClipListModel(QObject *parent = 0);
    ~ClipListModel();
    int rowCount(const QModelIndex &parent = QModelIndex() ) const;
    int columnCount(const QModelIndex &parent = QModelIndex() ) const;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

private:
    QVector<clipinfo> ClipInfo;
};

#endif