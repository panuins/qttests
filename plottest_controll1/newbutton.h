#ifndef NEWBUTTON_H
#define NEWBUTTON_H
#include <QWidget>
#include <QPushButton>
#include <qpainter.h>

class newbutton : public QPushButton
{
public:
    newbutton(QWidget *parent=0);

protected:
    virtual void paintEvent(QPaintEvent *event);

};

#endif // NEWBUTTON_H
