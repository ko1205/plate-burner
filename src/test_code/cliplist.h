#ifndef CLIPLIST_H
#define CLIPLIST_H

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class QLineEdit;
class QTableView;
class myTableModel;
class QPushButton;

class ClipList : public QWidget
{
    Q_OBJECT

public:
    ClipList(QWidget *parent = 0,Qt::WindowFlags f = 0);
    virtual ~ClipList();

    void setRootPath(QString &Path);

    void findClip(QString path);

    void setWin();

private:
    QWidget *win;               //List 기본창
    QVBoxLayout *layout;        //상단 레이아웃
    QHBoxLayout *toplayout;     //
    QString *rootPath;
    QLineEdit *LineEdit;
    QTableView *tableView;
    myTableModel *model;
    QPushButton *button;
    QStringList SequenceList;
};

#endif