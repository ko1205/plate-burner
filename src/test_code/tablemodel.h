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
    private:
        QMap<int,QMap<QString,QString>> temp;
};
