#include "mainview.h"
#include "mainmodel.h"
#include "mainwindow.h"
#include <QTableWidget>
#include <QFileDialog>

MainView::MainView(MainModel &mainModel)
{
    model = &mainModel;
    mainWin = new MainWindow();
};

MainView::~MainView()
{
};

void MainView::show()
{
    int column = model->getColumn();
    int row = model->getRow();
    mainWin->table->setColumnCount(column);
    mainWin->table->setRowCount(row);
    mainWin->table->setSpan(3,3,2,2);
    
    mainWin->show();
    QFileDialog dialog;
    dialog.exec();

};