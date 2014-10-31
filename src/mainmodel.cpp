#include "mainmodel.h"

MainModel::MainModel()
{
    column = 10;
    row = 10;
};

MainModel::~MainModel()
{
};

int MainModel::setColumn(int count)
{
    return column = count;
};

int MainModel::setRow(int count)
{
    return row = count;
};

int MainModel::getColumn()
{
    return column;
};

int MainModel::getRow()
{
    return row;
}