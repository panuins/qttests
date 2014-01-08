#include <QCoreApplication>
#include <QColor>
#include <QStringList>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QColor color(200,180,220,210);
    std::cout<<"color name:"<<color.name().toStdString()<<std::endl;
    QString strColorNameList;
    strColorNameList=QColor::colorNames().join("\n");
    std::cout<<"name list\n"<<strColorNameList.toStdString()<<std::endl;
    
    return a.exec();
}
