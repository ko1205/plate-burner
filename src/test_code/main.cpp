#include "mainwindow.h"
#include <QApplication>
#include "cliplist.h"

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    ClipList *list = new ClipList();
    list->show();
    app.exec();
}

