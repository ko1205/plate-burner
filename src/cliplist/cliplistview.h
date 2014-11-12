#ifndef CLIPLISTVIEW_H
#define CLIPLISTVIEW_H

#include <QTableView>

class ClipListView : public QTableView
{
    Q_OBJECT

public:
    ClipListView(QWidget *parent=0);
    ~ClipListView();

};

#endif