#include "mypainttestclass.h"

mypainttestclass::mypainttestclass(QWidget *parent) :
    QWidget(parent)
{
    mycolortest1=Qt::black;
    mycolortest2=Qt::white;
}

void mypainttestclass::paintEvent(QPaintEvent* event)
{
    int tablepointsize=40;
    QPainter mypaintertest(this);
    mypaintertest.setRenderHint(QPainter::NonCosmeticDefaultPen,true);
    mypaintertest.setPen(QPen(QBrush(mycolortest1), 1, Qt::SolidLine));
    mypaintertest.setBrush(QBrush(mycolortest2, Qt::SolidPattern));
    mypaintertest.setWindow(-(this->width()-tablepointsize)/2,-(this->height()-tablepointsize)/2,
                                 this->width(),this->height());
    mypaintertest.drawRect(10,10,50,50);
}
