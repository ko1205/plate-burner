#include<QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	MainWindow();
	~MainWindow();
private:
		QAction *newAction;
		QMenu *fileMenu;
		void createAction();
		void createMenu();

};
