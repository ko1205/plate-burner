#include <mainwindow.h>
#include <QApplication>
#include <QTableView>
#include "tablemodel.h"
#include "cliplist.h"

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    //MainWindow *mainWin = new MainWindow();
    //mainWin -> show();
    //QTableView *win = new QTableView();
    //myTableModel *model = new myTableModel();
    //win->setModel(model);
    //win->show();
    //win->resize(800,900);
    ClipList *list = new ClipList();
    list->show();
    app.exec();
}

