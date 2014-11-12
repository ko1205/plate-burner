#include "mainwindow.h"
//#include "sheetview.h"
#include <QTableView>
#include <QTableWidget>
#include "tablemodel.h"
#include <qmap.h>
//#include <QModelIndex>
//#include <QHBoxLayout>

MainWindow::MainWindow()
{
//    sheetview = new SheetView();
    QTableView *table = new QTableView();
//    QTableWidget *table = new QTableWidget();
    myTableModel *model = new myTableModel();
    table->setModel(model);
    for (int i=0;i < model->rowCount();i++){
        table->setRowHeight(i,150);
    }
    table->setColumnWidth(0,200);
    table->resize(800,900);
//    QMap<QString,int>::
//    setCentralWidget(sheetview);
    //QWidget *test = new QWidget();
    //QHBoxLayout *layout = new QHBoxLayout();
    //layout->addWidget(table);
    //test->setLayout(layout);
    setCentralWidget(table);
}

MainWindow::~MainWindow()
{
    delete sheetview;
}
