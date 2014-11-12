#include "cliplist.h"
//#include <QVBoxlayout>
//#include <QLabel>
//#include <QLineEdit>
//#include <QVBoxLayout>
//#include <QTableView>
//#include <QPushButton>
#include <QtGui>
#include "tablemodel.h"

ClipList::ClipList(QWidget *parent,Qt::WindowFlags f)
{
    setWin();
}

ClipList::~ClipList()
{

}

void ClipList::setRootPath(QString &Path)
{
    
}

void ClipList::findClip(QString path)
{

}

void ClipList::setWin()
{
    QString test = QFileDialog::getExistingDirectory();
    LineEdit = new QLineEdit(test);
    button = new QPushButton("root path");
    tableView = new QTableView();
    model = new myTableModel();
    tableView->setModel(model);
    layout = new QVBoxLayout();
    toplayout = new QHBoxLayout();
    toplayout->addWidget(LineEdit);
    toplayout->addWidget(button);
    layout->addLayout(toplayout);
    layout->addWidget(tableView);
    this->setLayout(layout);

}