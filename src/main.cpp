#include <QApplication>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    QLable *label = new QLabel("init project");
    label->show();
    return app.exec();
}
