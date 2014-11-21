#ifndef CLIPLISTDELEGATE_H
#define CLIPLISTDELEGATE_H

#include <QStyledItemDelegate>

class ClipListDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    ClipListDelegate(QObject *parent = 0);
    ~ClipListDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif