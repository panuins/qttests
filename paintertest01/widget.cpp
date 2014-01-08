#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //mycolortest1=Qt::black;
    //mycolortest2=Qt::white;
    testtoplot=new mypainttestclass(this);//(4,45,17,2,false,this);
    ui->verticalLayout->addWidget(testtoplot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent* event)
{
    /*int tablepointsize=40;
    QPainter mypaintertest(this);
    mypaintertest.setRenderHint(QPainter::NonCosmeticDefaultPen,true);
    mypaintertest.setPen(QPen(QBrush(mycolortest1), 1, Qt::SolidLine));
    mypaintertest.setBrush(QBrush(mycolortest2, Qt::SolidPattern));
    mypaintertest.setWindow(-(this->width()-tablepointsize)/2,-(this->height()-tablepointsize)/2,
                                 this->width(),this->height());
    mypaintertest.drawRect(10,10,50,50);*/
}
