#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QString>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = 0);

    void setMessage(const QString &message);
    void stop();
    
signals:
    
public slots:

protected:
    void run();
    
private:
    QString message_content;
    volatile bool stopped;
};

#endif // MYTHREAD_H
