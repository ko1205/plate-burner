#include "tablemodel.h"
#include <QPushButton>
#include <iostream>

myTableModel::myTableModel(QObject *parent) : QAbstractTableModel(parent)
{
}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    return 5;
}

int myTableModel::columnCount(const QModelIndex &parent) const
{
    return 8;
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.column() == 0){
        if (role == Qt::DecorationRole){ 
            return QPixmap("thumnail/A028_C007_0530RS.0000508.jpg");
        }
    }else if (role == Qt::TextAlignmentRole){
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    } else if (role == Qt::DisplayRole){
	    return QString(tr("test")); 
    }
    return QVariant();
}


QVariant myTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal){
        if(role == Qt::DisplayRole){
            return QString(tr("horizontal"));
        //}else if(role == Qt::SizeHintRole){
        //    return QSize(1200,50);
        }
    }else {
    //    if(role == Qt::DisplayRole){
    //        return QString(tr("Vertical"));
    //    //}else if(role == Qt::SizeHintRole){
    //    //    return QSize(100,300);
    //    }
        return QAbstractTableModel::headerData(section,orientation,role);
    }
    return QVariant();
}

Qt::ItemFlags myTableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |= Qt::ItemIsEditable;
    return flags;
}
