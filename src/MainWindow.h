#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    virtual ~MainWindow();
private:
    QAction *newAction;

    QMenu *fileMenu;
    QMenu *editMenu;

    void createAction();
    void createMenu();
};
