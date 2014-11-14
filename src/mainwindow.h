#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cliplist/cliplistmodel.h"

class QTableWidget;
class QMdiArea;
class QProgressBar;
class ClipListWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    virtual ~MainWindow();
    QTableWidget *table;
    QMdiArea *mdi;

private:
    int rowCount;
    QAction *newAction;
    QAction *openAction;

    QAction *copyAction;
    
    QMenu *fileMenu;
    QMenu *editMenu;

    QProgressBar *progressbar;
    ClipListModel *model;

    void createAction();
    void createMenu();
    void createStatusBar();

public slots:
    void test();
    void NewFile();
    void StatusBarMessage(QString filename);
};

#endif