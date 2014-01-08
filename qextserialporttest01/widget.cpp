#include "widget.h"
#include "ui_widget.h"
#include "deviceinfo.h"
#include <QString>
#include <QByteArray>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->onPortChanged();
    PortSettings usart_settings = {USART_BAUD_RATE,
                                   USART_BIT_TYPE,
                                   USART_PARITY_TYPE,
                                   USART_STOP_BITS_TYPE,
                                   USART_FLOW_TYPE,
                                   10};
    usartport=new QextSerialPort(ui->comboBox_port->currentText(),usart_settings,QextSerialPort::EventDriven);
    usartdevice_enumerator=new QextSerialEnumerator(this);
    usartdevice_enumerator->setUpNotifications();

    connect(usartport,SIGNAL(readyRead()),this,SLOT(onreceived()));
    connect(usartdevice_enumerator,SIGNAL(deviceDiscovered(QextPortInfo)),this,SLOT(onPortChanged()));
    connect(usartdevice_enumerator,SIGNAL(deviceRemoved(QextPortInfo)),this,SLOT(onPortChanged()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPortChanged()
{
    QString currentport=ui->comboBox_port->currentText();
    ui->comboBox_port->blockSignals(true);
    ui->comboBox_port->clear();
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
    {
        ui->comboBox_port->addItem(info.portName);
    }

    ui->comboBox_port->setCurrentIndex(ui->comboBox_port->findText(currentport));
    ui->comboBox_port->blockSignals(false);
    std::cout<<"reset usart port."<<std::endl;
}

void Widget::onreceived()
{
    QByteArray received;
    int i=0;
    if(usartport->bytesAvailable())
    {
        received=usartport->readAll();
        ui->textBrowser_received->insertPlainText(QString::fromLatin1(received));
        for(;i<received.size();i++)
        {
            ui->textBrowser_received_hex->insertPlainText(QString::fromLatin1(received.mid(i,1).toHex())
                                                          +QString(" "));
        }
        //std::cout<<"received data: "<<QString::fromLatin1(received).toStdString()<<std::endl;
    }
    else
    {
        std::cout<<"Warning: received data, but port's bytes are not available."<<std::endl;
    }
}

void Widget::on_pushButton_open_clicked()
{
    if(usartport->isOpen())  //open -> close
    {
        ui->pushButton_open->setText("&Open");
        usartport->close();
    }
    else  //close -> open
    {
        usartport->setPortName(ui->comboBox_port->currentText());
        usartport->open(QIODevice::ReadWrite);
        if(usartport->isOpen())
        {
            ui->pushButton_open->setText("&Close");
        }
        else
        {
            std::cout<<"Warning: open port "<<ui->comboBox_port->currentText().toStdString()<<" failed."<<std::endl;
        }
    }
}

void Widget::on_pushButton_send_clicked()
{
    qint64 sendedbytes;
    if(!usartport->isOpen())
    {
        std::cout<<"Error: usart port not opened. Can't send data."<<std::endl;
        return;
    }
    if(ui->textEdit_tosend_hex->toPlainText().isEmpty())
    {
        std::cout<<"Error: text box is empty. Can't send data."<<std::endl;
        return;
    }
    sendedbytes=usartport->write(QByteArray::fromHex(ui->textEdit_tosend_hex->toPlainText().toLatin1()));
    std::cout<<"send "<<sendedbytes<<"bytes."<<std::endl;
}

void Widget::on_textEdit_tosend_textChanged()
{
    ui->textEdit_tosend_hex->blockSignals(true);
    ui->textEdit_tosend_hex->setText(QString::fromLatin1(ui->textEdit_tosend->toPlainText().toLatin1().toHex()));
    ui->textEdit_tosend_hex->blockSignals(false);
}

void Widget::on_textEdit_tosend_hex_textChanged()
{
    ui->textEdit_tosend->blockSignals(true);
    ui->textEdit_tosend->setText(QString::fromLatin1(QByteArray::fromHex(ui->textEdit_tosend_hex->toPlainText().toLatin1())));
    ui->textEdit_tosend->blockSignals(false);
}
