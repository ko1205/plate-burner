#ifndef CLIPLISTDELEGATE_H
#define CLIPLISTDELEGATE_H

#include <QItemDelegate>

class ClipListDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ClipListDelegate(QObject *parent = 0);
    ~ClipListDelegate();

};

#endif