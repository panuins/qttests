#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QPainter>
#include <QColor>
#include <QRect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    if(!myimage.load("300px-Phase-diag-zh.svg.png"))
    {
        std::cout<<"read file failed."<<std::endl;
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent* event)
{
    QPainter mypainter(this);
    QRect myimagesize(0,0,2*myimage.rect().width(),2*myimage.rect().width());

    if(!myimage.isNull())
    {
        mypainter.drawImage(myimagesize,myimage,myimage.rect());
    }
}

void Widget::on_pushButton_read_clicked()
{
    QRgb rgbavalue;

    rgbavalue=myimage.pixel(ui->lineEdit_x->text().toInt(), ui->lineEdit_y->text().toInt());
    ui->lineEdit_r->setText(QString("%1").arg(qRed(rgbavalue)));
    ui->lineEdit_g->setText(QString("%1").arg(qGreen(rgbavalue)));
    ui->lineEdit_b->setText(QString("%1").arg(qBlue(rgbavalue)));
    ui->lineEdit_a->setText(QString("%1").arg(qAlpha(rgbavalue)));
}

void Widget::on_pushButton_set_clicked()
{
    QColor pointcolor(ui->lineEdit_r->text().toInt(),ui->lineEdit_g->text().toInt(),ui->lineEdit_b->text().toInt(),ui->lineEdit_a->text().toInt());
    QPoint pointdata(ui->lineEdit_x->text().toInt(),ui->lineEdit_y->text().toInt());

    myimage.setPixel(pointdata,pointcolor.rgba());
    update();
}

void Widget::on_pushButton_save_clicked()
{
    myimage.save(QString("300px-Phase-diag-zh_modified.png"));
}
