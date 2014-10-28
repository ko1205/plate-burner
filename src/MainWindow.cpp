#include<QtGui>
#include "MainWindow.h"

MainWindow::MainWindow()
{
	QWidget *widget = new QWidget;
	setCentralWidget(widget);
	createAction();
	createMenu();

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
}