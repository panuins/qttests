#include "newbutton.h"

newbutton::newbutton(QWidget *parent) //:
    //QWidget(parent)
{
}

void newbutton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawRect(0,0,10,10);//this->width(),this->height());
}
