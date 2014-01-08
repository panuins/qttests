#ifndef MYPAINTTESTCLASS_H
#define MYPAINTTESTCLASS_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>

class mypainttestclass : public QWidget
{
    Q_OBJECT
public:
    explicit mypainttestclass(QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent* event);

private:
    /*QColor linecolor;
    QColor unfoundgirdcolor,foundgirdcolor;
    QColor unfoundgirdnumbercolor,foundgirdnumbercolor;
    QFont unfoundgirdnumberfont,foundgirdnumberfont;*/
    QColor mycolortest1,mycolortest2;
    QFont myfonttest1,myfonttest2;
    int tablesize,girdsize,fontsize;
    int linewidth;
};

#endif // MYPAINTTESTCLASS_H
