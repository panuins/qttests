#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>

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

private slots:
    void on_pushButton_read_clicked();

    void on_pushButton_set_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::Widget *ui;
    QImage myimage;
};

#endif // WIDGET_H
