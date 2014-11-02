#include <QMainWindow>

class SheetView;

class MainWindow : public QMainWindow
{
    Q_OBJECT;

    public:
        MainWindow();
        virtual ~MainWindow();
    private:
        SheetView *sheetview;
};
