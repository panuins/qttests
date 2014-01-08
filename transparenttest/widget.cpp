#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setWindowOpacity(0.5);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    //this->setAttribute(Qt::WA_TransparentForMouseEvents);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(0,255,255,100)));
    painter.drawRect(0,0,this->width()/2,this->height()/2);
    painter.setBrush(QBrush(QColor(0,255,0,200)));
    painter.drawRect(this->width()/2,0,this->width()/2,this->height()/2);
    painter.setBrush(QBrush(QColor(0,255,255,255)));
    painter.drawRect(0,this->height()/2,this->width()/2,this->height()/2);
    painter.setBrush(QBrush(QColor(0,255,0,0)));
    painter.drawRect(this->width()/2,this->height()/2,this->width()/2,this->height()/2);
}
