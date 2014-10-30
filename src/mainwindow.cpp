#include <QtGui>
#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow()
{
    QPushButton *button = new QPushButton("test");
    QTableWidget *table = new QTableWidget();
    table->setRowCount(30);
    table->setColumnCount(20);
    table->setColumnWidth(0,200);
    for(int i =0;i<30;i++){
        table->setRowHeight(i,200);
    }
    table->setCellWidget(0,0,button);
    table->setSortingEnabled(true);
    setCentralWidget(table);
	createAction();
	createMenu();

// Window 화면 설정
    setWindowTitle(tr("test_window"));
    resize(800,600);

    connect(button,SIGNAL(clicked()),this,SLOT(test()));
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
    std::cout<<"test\n";
}