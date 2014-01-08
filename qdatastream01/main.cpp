#include <QCoreApplication>
#include <QtGlobal>
#include <QFile>
#include <QDataStream>
#include <QVector>

#include <iostream>
#include <cstdlib>
#include <cstdio>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile testfile(QString("testfile"));
    QFile testfile2(QString("test"));

    //test code
    /*QVector<int> b3(1<<28);
    qint64 i=0;
    std::cout<<b3.size()<<std::endl;
    for(;i<(1<<28);i++)
    {
        b3[i]=i;
    }
    std::cout<<b3.at((1<<28)-1)<<std::endl;*/

    char b[]="abcdefghijklm\0nopqrst\xF0\xE4";
    char b3[]="abcdefghijklmn";
    char *b1=new char[100];
    char *b2=new char[1<<28];
    int c[1<<20]={32,33,34};

    if(b2==NULL)
    {
        std::cerr<<"Error alloc memory failed."<<std::endl;
    }

    b2[(1<<28)-1]='a';
    std::cout<<b2[(1<<28)-1]<<std::endl;

    /*if(!testfile.exists())
    {
        system("touch testfile");
    }
    else
    {
        system("rm testfile");
        system("touch testfile");
    }*/

    if(!testfile.open(QIODevice::WriteOnly))
    {
        std::cerr<<"Error: can't open file testfile."<<std::endl;
        return 1;
    }

    //QDataStream mystreamw(&testfile);
    //mystream.setVersion(QDataStream::Qt_4_8);

    //mystream<<b<<'\0'<<c[0]<<c[1]<<c[2]<<b;
    //mystreamw.writeBytes(b,sizeof(b));
    testfile.write(b3,sizeof(b3)-1);
    testfile.write(b3,sizeof(b3)-1);

    testfile.close();


    if(!testfile.open(QIODevice::ReadOnly))
    {
        std::cerr<<"Error: can't open file testfile."<<std::endl;
        return 1;
    }

    //std::cout<<"file size:"<<testfile.size()<<" stringsize:"<<sizeof(b)<<std::endl;
    //QDataStream mystreamr(&testfile);
    //mystreamr>>b1;
    testfile.read(b1,testfile.size());

    testfile.close();

    if(!testfile2.open(QIODevice::ReadOnly))
    {
        std::cerr<<"Error: can't open file test."<<std::endl;
        return 1;
    }

    //QDataStream mystream2r(&testfile);
    //mystream2r>>b2;
    testfile.read(b2,testfile.size());

    testfile2.close();

    std::cout<<b1<<' '<<&(b1[strlen(b1)+1])<<std::endl;
    std::cout<<"success"<<std::endl;
    std::cout<<"not break"<<std::endl;
    
    delete [] b1;
    delete [] b2;

    return a.exec();
}
