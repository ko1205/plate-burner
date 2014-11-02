#include "tablemodel.h"
#include <QPushButton>

myTableModel::myTableModel(QObject *parent) : QAbstractTableModel(parent)
{
}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    return 5;
}

int myTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole){
        return int(Qt::AlignRight | Qt::AlignVCenter);
    } else if (role == Qt::DisplayRole){
//    return QVariant();
//		if (index.column() == 0){
//			QPushButton *button = new QPushButton(tr("Push"));
//			return *button;
//		}else{
		    return QString(tr("test")); 
//        }
    } else if (role == Qt::DecorationRole){ 

        return QIcon();
	}
    return QVariant();
}

Qt::ItemFlags myTableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |= Qt::ItemIsEditable;
    return flags;
}
