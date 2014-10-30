#include "mainview.h"
#include "mainmodel.h"
#include "mainwindow.h"

MainView::MainView(MainModel &mainModel)
{
    model = &mainModel;
};

MainView::~MainView()
{
};

void MainView::show()
{
    MainWindow *mainWin = new MainWindow();
    mainWin->show();

};