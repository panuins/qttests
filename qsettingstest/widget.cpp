#include "widget.h"
#include "ui_widget.h"
#include <QSettings>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_write_clicked()
{
    QSettings settings("panuins","test");
    settings.setValue("key1",1);
    settings.setValue("key1/a","ase");
    settings.setValue("key1/b","ewse");
    settings.setValue("key1/b/c","ewwqe");
    settings.setValue("key1/b/d","eawqe");
    settings.setValue("key2","3ew");
}
