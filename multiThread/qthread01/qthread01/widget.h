#ifndef WIDGET_H
#define WIDGET_H

#include "mythread.h"
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
    
private slots:
    void on_pushButton_A_clicked();

    void on_pushButton_B_clicked();

private:
    Ui::Widget *ui;
    mythread threadA;
    mythread threadB;
};

#endif // WIDGET_H
