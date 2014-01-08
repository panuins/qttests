#ifndef WIDGET_H
#define WIDGET_H

#include "mypainttestclass.h"
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent* event);

private:
    /*QColor linecolor;
    QColor unfoundgirdcolor,foundgirdcolor;
    QColor unfoundgirdnumbercolor,foundgirdnumbercolor;
    QFont unfoundgirdnumberfont,foundgirdnumberfont;*/
    /*QColor mycolortest1,mycolortest2;
    QFont myfonttest1,myfonttest2;
    int tablesize,girdsize,fontsize;
    int linewidth;*/
    mypainttestclass *testtoplot;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
