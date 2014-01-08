#include <QCoreApplication>
#include <QCryptographicHash>
#include <QByteArray>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout<<QCryptographicHash::hash(QByteArray("a"),QCryptographicHash::Sha1).data()<<std::endl;
    std::cout<<QCryptographicHash::hash(QByteArray("a"),QCryptographicHash::Sha1).toHex().data()<<std::endl;
    return a.exec();
}
