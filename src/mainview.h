#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QObject>

class MainModel;
class MainWindow;

class MainView : public QObject
{
    Q_OBJECT;

public:
    MainView(MainModel &model);
    virtual ~MainView();
    void show();
private:
    MainModel *model;
    MainWindow *mainWin;

};

#endif