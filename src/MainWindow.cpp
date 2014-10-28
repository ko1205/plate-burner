#include <QtGui>
#include "MainWindow.h"

MainWindow::MainWindow()
{
	createAction();
	createMenu();


// Window 화면 설정
    setWindowTitle(tr("test_window"));
    resize(800,600);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createAction()
{
	newAction = new QAction(tr("&New"),this);
}

void MainWindow::createMenu()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
}