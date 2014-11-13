#ifndef CLIPLISTWINDOW_H
#define CLIPLISTWINDOW_H

#include <QWidget>

class QVBoxLayout;

class ClipListWindow : public QWidget
{
    Q_OBJECT

public:
    ClipListWindow(QWidget *parent = (QWidget*)0,Qt::WindowFlags f = 0);
    virtual ~ClipListWindow();

private:
    QVBoxLayout *layout;

};

#endif