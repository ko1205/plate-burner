#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>

class MainModel : public QObject
{
    Q_OBJECT;

public:
    MainModel();
    virtual ~MainModel();
    int setColumn(int count);
    int setRow(int count);
    int getColumn();
    int getRow();
private:
    int column;
    int row;

};

#endif