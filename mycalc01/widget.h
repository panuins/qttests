#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;

private slots:
    void on_lineEdit_2_cursorPositionChanged(int , int );
    void on_lineEdit_cursorPositionChanged(int , int );
    void on_pushButton_clicked();
};

#endif // WIDGET_H
