#include "widget.h"
#include "ui_widget.h"

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

//样式表测试
void Widget::on_pushButton_clicked()
{
    qApp->setStyleSheet("QLineEdit{background-color:blue;}"    //将所有QLineEdit的背景色设为蓝色
                        "QCheckBox#checkBox::indicator{width:30px;height:30px;}"  //将checkBox的选择器的大小设为30x30 no
                        "QCheckBox#checkBox{spacing:10px;}"  //将checkBox的选择器的前后距离设为10px
                        "QCheckBox#checkBox:hover,QCheckBox#checkBox:checked{color:white;}"  //当鼠标在checkBox中悬停时，当复选框被选中时，将文字设为白色
                        );
    //this->setStyleSheet("background-color:rgba(100%,100%,100%,20%);");    //将主窗体的背景设为白色+20%透明
    ui->label->setStyleSheet("color:rgb(0,88,152);background-color:yellow;");   //将label的背景色设为黄色，前景色设为rgb(0,88,152)
    ui->comboBox->setStyleSheet("background-color:rgba(100%,100%,100%,20%);");    //将comboBox的背景设为白色+20%透明
    ui->plainTextEdit->setStyleSheet("background-color:qlineargradient(X1:0,y1:0,x2:1,y2:1,"
                                     "stop:0 white,stop:0.4 gray,stop:1 green);");  //将plainTextEdit的背景色设为由白到绿色渐变的效果
    ui->plainTextEdit_2->setStyleSheet("background-image:url(:/pic/schrodingerscat.png);");  //为plainTextEdit_2添加背景图片
    //ui->checkBox
}
