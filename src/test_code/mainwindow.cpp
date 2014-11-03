#include "mainwindow.h"
//#include "sheetview.h"
#include <QTableView>
#include "tablemodel.h"
#include <qmap.h>
#include <QModelIndex>

MainWindow::MainWindow()
{
//    sheetview = new SheetView();
    QTableView *table = new QTableView();
    myTableModel *model = new myTableModel();
    table->setModel(model);
    for (int i=0;i < model->rowCount();i++){
        table->setRowHeight(i,150);
    }
    table->setColumnWidth(0,200);
//    QMap<QString,int>::
//    setCentralWidget(sheetview);
    setCentralWidget(table);
}

MainWindow::~MainWindow()
{
    delete sheetview;
}
