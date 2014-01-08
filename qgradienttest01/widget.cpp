#include "widget.h"
#include "ui_widget.h"
#include <QBrush>
#include <QColor>
#include <QLinearGradient>
#include <QPainter>
#include <QPen>
#include <QRadialGradient>

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

void Widget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QRadialGradient gradientEffectRect(150, 150, 100);
    gradientEffectRect.setColorAt(0.0, QColor(62, 52, 11));
    gradientEffectRect.setColorAt(0.2, QColor(62, 52, 11));
    gradientEffectRect.setColorAt(1.0, Qt::transparent);
    QLinearGradient gradientEffectLine(0.0, 0.0, 300.0, 0.0);
    gradientEffectLine.setColorAt(0.0, Qt::transparent);
    gradientEffectLine.setColorAt(0.5, Qt::green);
    gradientEffectLine.setColorAt(1.0, Qt::transparent);
    QBrush brushRect(gradientEffectLine);
    QBrush brushLine(gradientEffectLine);
    QPen pen(brushLine, 3);
    //pen.setColor(Qt::green);

    QPainter painter(this);
    painter.setBrush(brushRect);
    painter.setPen(pen);
    painter.drawRect(50, 50, 200, 200);
}
