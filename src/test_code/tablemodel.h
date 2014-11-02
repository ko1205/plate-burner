#include <QAbstractTableModel>

class myTableModel : public QAbstractTableModel
{
    public:
        myTableModel(QObject *parent = 0 );

        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

		Qt::ItemFlags flags(const QModelIndex &index) const;
    private:
};
