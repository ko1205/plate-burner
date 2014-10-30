#include <QApplication>
#include "control.h"
#include "mainmodel.h"
#include "mainview.h"

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    MainModel mainModel;
    MainView mainView(mainModel);
    ControlMain control(app,mainView,mainModel);     
    return control.run();
}
