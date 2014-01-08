#include "widget.h"
#include "ui_widget.h"
#include <QShortcut>
#include <QKeySequence>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QShortcut *shortcut = new QShortcut(QKeySequence(tr("Ctrl+S")), ui->widget_test);
    //shortcut->setContext(Qt::ApplicationShortcut);
    //shortcut->setContext(Qt::WidgetShortcut);
    //ui->lineEdit->hide();
    connect(shortcut, SIGNAL(activated()), this, SLOT(print()));
    connect(shortcut, SIGNAL(activatedAmbiguously()), this, SLOT(print2()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::print()
{
    std::cout << "activated" << std::endl;
}

void Widget::print2()
{
    std::cout << "activatedAmbiguously" << std::endl;
}

void Widget::on_pushButton_clicked()
{
    this->setWindowState(Qt::WindowFullScreen);
}

void Widget::on_pushButton_2_clicked()
{
    this->setWindowState(Qt::WindowNoState);
}
