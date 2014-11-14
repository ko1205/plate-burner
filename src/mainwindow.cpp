#include "MainWindow.h"
#include "cliplist/cliplistwindow.h"
#include <QtGui>

MainWindow::MainWindow()
{
    createAction();
	createMenu();
    createStatusBar();
    mdi = new QMdiArea();
    setCentralWidget(mdi);

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
    statusBar()->addWidget(new QLabel("test"),1);
    statusBar()->addWidget(progressbar);
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

    model = new ClipListModel();

    connect(model,SIGNAL(readClip(QString)),this,SLOT(StatusBarMessage(QString)));
    model->searchDir(QFileDialog::getExistingDirectory().replace("\\","/"),QStringList("*.dpx"));
    QMdiSubWindow *subwin = mdi->addSubWindow(new ClipListWindow(model));
    subwin->showMaximized();
}

void MainWindow::StatusBarMessage(QString filename)
{
    statusBar()->showMessage(filename,0);
}