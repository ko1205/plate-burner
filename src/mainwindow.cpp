#include <QtGui>
#include "MainWindow.h"
#include <iostream>
#include <QDir>
#include "cliplist\cliplistwindow.h"
#include <QTimer>

MainWindow::MainWindow()
{
    createAction();
	createMenu();
    mdi = new QMdiArea();
    setCentralWidget(mdi);
    QTimer::singleShot(0,this,SLOT(test()));



// Window 화면 설정
    setWindowTitle(tr("test_window"));
    resize(800,600);

    //connect(button,SIGNAL(clicked()),this,SLOT(test()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createAction()
{
	newAction = new QAction(tr("&New"),this);
    copyAction = new QAction(tr("&copy"),this);
}

void MainWindow::createMenu()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu -> addAction(copyAction);
}

void MainWindow::test()
{
    ClipListWindow *view = new ClipListWindow();
    QMdiSubWindow *subwindow = mdi->addSubWindow(view);
    subwindow->show();
    view->showMaximized();

}