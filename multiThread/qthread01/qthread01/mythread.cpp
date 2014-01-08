#include "mythread.h"
#include <iostream>

mythread::mythread(QObject *parent) :
    stopped(false),
    QThread(parent)
{
}

void mythread::setMessage(const QString &message)
{
    message_content=message;
}

void mythread::stop()
{
    stopped=true;
}

void mythread::run()
{
    stopped=false;
    while(!stopped)
    {
        std::cout<<qPrintable(message_content);
    }
    std::cout<<std::endl;
}
