#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QObject>

class MainModel;

class MainView : public QObject
{
    Q_OBJECT;

public:
    MainView(MainModel &model);
    virtual ~MainView();
    void show();
private:
    MainModel *model;

};

#endif