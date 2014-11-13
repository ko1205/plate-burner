#include "cliplistwindow.h"
#include "cliplistview.h"
#include "cliplistmodel.h"
#include "cliplistdelegate.h"
#include <QVBoxLayout>

ClipListWindow::ClipListWindow(QWidget *parent,Qt::WindowFlags f)
    :QWidget(parent,f)
{
    ClipListView *list = new ClipListView(this);
    ClipListModel *model = new ClipListModel("E:/test_images/dd",QStringList("*.dpx")<<"*.jpg");
    //ClipListModel *model = new ClipListModel("Z:/___work___/myheart/asset/original_plate/CG_0915/RED",QStringList("*.dpx"));
    list->setModel(model);
    list->setItemDelegate(new ClipListDelegate);
    layout = new QVBoxLayout();
    layout->addWidget(list);
    this->setLayout(layout);
}

ClipListWindow::~ClipListWindow()
{

}