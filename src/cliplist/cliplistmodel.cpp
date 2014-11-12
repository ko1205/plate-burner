#include "cliplistmodel.h"

ClipListModel::ClipListModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

ClipListModel::~ClipListModel()
{

}

int ClipListModel::rowCount(const QModelIndex &parent) const
{
    return 5;
}

int ClipListModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant ClipListModel::data(const QModelIndex &index, int role) const
{
    return QVariant();

}

QVariant ClipListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QAbstractTableModel::headerData(section,orientation,role);
}