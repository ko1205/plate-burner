#include "mainwindow.h"
#include "cliplist/cliplistwindow.h"
#include <QtGui>
#include <QMdiArea>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QLabel>
#include <QStatusBar>
#include <QMdiSubWindow>
#include <QFileDialog>

MainWindow::MainWindow()
{
    createAction();
	createMenu();
    createStatusBar();
    mdi = new QMdiArea();
    setCentralWidget(mdi);

// Window 화면 설정
    setWindowTitle(tr("plate-burner"));
    resize(800,600);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createAction()
{
	newAction = new QAction(tr("&New"),this);
    openAction = new QAction(tr("&Open"),this);

    copyAction = new QAction(tr("&copy"),this);
    connect(newAction,SIGNAL(triggered()),this,SLOT(NewFile()));
}

void MainWindow::createMenu()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu -> addAction(copyAction);
}

void MainWindow::createStatusBar()
{
    progressbar = new QProgressBar();
    statusMessage = new QLabel("test");
//    label->setIndent(150);
    statusBar()->addWidget(statusMessage,1);
}

void MainWindow::test()
{
    ClipListWindow *view = new ClipListWindow();
    QMdiSubWindow *subwindow = mdi->addSubWindow(view);
    subwindow->show();
    view->showMaximized();
}

void MainWindow::NewFile()
{
    statusBar()->addWidget(progressbar);
    model = new ClipListModel();

    connect(model,SIGNAL(readClip(QString)),this,SLOT(StatusBarMessage(QString)));
    model->searchDir(QFileDialog::getExistingDirectory().replace("\\","/"),QStringList("*.dpx"));
    QMdiSubWindow *subwin = mdi->addSubWindow(new ClipListWindow(model));
    subwin->showMaximized();
    statusBar()->removeWidget(progressbar);
}

void MainWindow::StatusBarMessage(QString filename)
{
//    statusMessage->setText(filename);
    statusBar()->showMessage(filename,0);
}
