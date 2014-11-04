#include <mainwindow.h>
#include <QApplication>
#include <QTableView>
#include "tablemodel.h"

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    MainWindow *mainWin = new MainWindow();
    mainWin -> show();
    //QTableView *win = new QTableView();
    //myTableModel *model = new myTableModel();
    //win->setModel(model);
    //win->show();
    //win->resize(800,900);
    app.exec();
}

