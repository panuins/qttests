#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QRegExp regExp("[0-9]*");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(regExp, this));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::on_pushButton_clicked()
{
    int a,b,c;
    a=ui->lineEdit->text().toInt();
    b=ui->lineEdit_2->text().toInt();
    c=a+b;
    ui->lineEdit_3->setText(QString("%1").arg(c));
}

void Widget::on_lineEdit_cursorPositionChanged(int , int )
{

}

void Widget::on_lineEdit_2_cursorPositionChanged(int , int )
{

}
