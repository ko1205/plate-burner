#include <QApplication>
#include "cliplistview.h"
#include "cliplistmodel.h"
#include "cliplistdelegate.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    ClipListView win;
    ClipListModel model;
    win.setModel(&model);
    win.setItemDelegate(new ClipListDelegate);
    win.show();
    return app.exec();
}