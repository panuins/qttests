#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    justabutton=new newbutton(this);
    ui->gridLayout->addWidget(justabutton);
}

Widget::~Widget()
{
    delete justabutton;
    delete ui;
}
