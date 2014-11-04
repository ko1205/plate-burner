#include <QAbstractTableModel>

class myTableModel : public QAbstractTableModel
{
    public:
        myTableModel(QObject *parent = 0 );

        int rowCount(const QModelIndex &parent=QModelIndex()) const;
        int columnCount(const QModelIndex &parent=QModelIndex()) const;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

		Qt::ItemFlags flags(const QModelIndex &index) const;

        void setmyTableModleMap(const QMap<int,QMap<QString,QString>> &map);

    private:
        QMap<int,QMap<QString,QString>> myModelMap;
};
