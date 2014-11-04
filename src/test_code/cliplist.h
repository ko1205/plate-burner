#ifndef CLIPLIST_H
#define CLIPLIST_H

#include <QWidget>

class QVBoxLayout;
class QLineEdit;
class QTableView;
class myTableModel;

class ClipList : public QWidget
{
    Q_OBJECT

public:
    ClipList(QWidget *parent = 0,Qt::WindowFlags f = 0);
    virtual ~ClipList();

private:
    QWidget *win;
    QVBoxLayout *layout;
    QString *rootPath;
    QLineEdit *LineEdit;
    QTableView *tableView;
    myTableModel * model;
};

#endif