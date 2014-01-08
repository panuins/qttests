#include "widget.h"
#include "ui_widget.h"
#include <QApplication>

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

void Widget::on_pushButton_clicked()
{
    QByteArray arg1 = QCoreApplication::arguments().at(0).toUtf8();
    char* fakeargv = arg1.data();
    int fakeargc = 1;
    //QApplication *a = new QApplication(fakeargc, &fakeargv);
    QApplication a(fakeargc, &fakeargv);
    //a.exec();
}
