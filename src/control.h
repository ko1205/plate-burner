#ifndef COLTROL_H
#define COLTROL_H

#include <QObject>

class QApplication;
class MainView;
class MainModel;

class ControlMain : QObject
{
    Q_OBJECT;

public:
    ControlMain(QApplication &app,MainView &mainview,MainModel &mainmodel);
    virtual ~ControlMain();

    int run();
private:
    QApplication *app;
    MainView *view;
    MainModel *model;

//public signals:
    
//public slots:
    
};

#endif