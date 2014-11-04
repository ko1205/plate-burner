#include "cliplist.h"
#include <QVBoxlayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTableView>
#include "tablemodel.h"

ClipList::ClipList(QWidget *parent,Qt::WindowFlags f)
{
    LineEdit = new QLineEdit("test_text_edit");
    tableView = new QTableView();
    model = new myTableModel();
    tableView->setModel(model);
    layout = new QVBoxLayout();
    layout->addWidget(LineEdit);
    layout->addWidget(tableView);
    this->setLayout(layout);

}

ClipList::~ClipList()
{

}

