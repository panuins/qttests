#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    threadA.setMessage(tr("A"));
    threadB.setMessage(tr("B"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_A_clicked()
{
    if(threadA.isRunning())
    {
        threadA.stop();
    }
    else
    {
        threadA.start();
    }
}

void Widget::on_pushButton_B_clicked()
{
    if(threadB.isRunning())
    {
        threadB.stop();
    }
    else
    {
        threadB.start();
    }
}
