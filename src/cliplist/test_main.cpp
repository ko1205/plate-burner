#include <QApplication>
#include "cliplistwindow.h"
//#include "cliplistview.h"
//#include "cliplistmodel.h"
//#include "cliplistdelegate.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    //ClipListView win;
    //ClipListModel model("E:/test_images/dd",QStringList("*.dpx")<<"*.jpg");
    //ClipListModel model("Z:/___work___/myheart/asset/original_plate/CG_0915/RED",QStringList("*.dpx"));
    //win.setModel(&model);
    //win.setItemDelegate(new ClipListDelegate);
    ClipListWindow win;
    win.show();
    return app.exec();
}