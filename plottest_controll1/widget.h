#ifndef WIDGET_H
#define WIDGET_H

#include "newbutton.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
    newbutton *justabutton;
};

#endif // WIDGET_H
