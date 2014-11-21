#include "cliplistdelegate.h"
#include <QLabel>
#include <QApplication>
ClipListDelegate::ClipListDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{

}

ClipListDelegate::~ClipListDelegate()
{

}

void ClipListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 6){
//        drawDisplay(painter,option,option.rect,"testaaaa");
        QStyleOptionViewItemV4 opt = option;
        opt.text = "testaaaa";
        opt.rect.setHeight(option.rect.height()/2);

        QStyleOptionProgressBar proOption;
        proOption.rect = option.rect;
        proOption.rect.setTop(option.rect.top()+option.rect.height()/2);
        proOption.minimum = 0;
        proOption.maximum = 100;
        proOption.progress = 50;
        QApplication::style()->drawControl(QStyle::CE_ItemViewItem,&opt,painter);
        QApplication::style()->drawControl(QStyle::CE_ProgressBar,&proOption,painter);

    }else
    QStyledItemDelegate::paint(painter,option,index);
}