#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    virtual ~MainWindow();
private:
    int rowCount;
    QAction *newAction;
    QAction *copyAction;

    QMenu *fileMenu;
    QMenu *editMenu;

    void createAction();
    void createMenu();

    public slots:
        void test();

};

#endif