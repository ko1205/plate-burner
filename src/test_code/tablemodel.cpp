#include "tablemodel.h"
#include <QPushButton>
#include <iostream>

myTableModel::myTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    for (int  i = 0; i<10 ;i++){
        QMap<QString,QString> temp;
        temp.insert("test01","");
        temp.insert("test02","002");
        temp.insert("test03","003");
        temp.insert("test04","004");
        myModelMap.insert(i,temp);
    }
}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    return myModelMap.count();
}

int myTableModel::columnCount(const QModelIndex &parent) const
{
    return myModelMap[0].count();
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
	    return QString(tr("test\nkkkk")); 
    }
    return QVariant();
}


QVariant myTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal){
        if(role == Qt::DisplayRole){
            return (myModelMap.begin().value().begin() + section).key();
        }
    }
    return QAbstractTableModel::headerData(section,orientation,role);
}

Qt::ItemFlags myTableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |= Qt::ItemIsEditable;
    return flags;
}

void myTableModel::setmyTableModleMap(const QMap<int,QMap<QString,QString>> &map)
{
    myModelMap = map;
}