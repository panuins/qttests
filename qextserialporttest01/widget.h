#ifndef WIDGET_H
#define WIDGET_H

#include "qextserialport.h"
#include "qextserialenumerator.h"
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

public slots:
    void onPortChanged();
    void onreceived();
    
private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_send_clicked();

    void on_textEdit_tosend_textChanged();

    void on_textEdit_tosend_hex_textChanged();

private:
    Ui::Widget *ui;
    QextSerialPort *usartport;
    QextSerialEnumerator *usartdevice_enumerator;
};

#endif // WIDGET_H
