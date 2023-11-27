#include <QCoreApplication>
#include <QFile>
#include <QByteArray>
#include <QDateTime>
#include <QString>
#include <iostream>
#include <string>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    std::string fileName;
    std::string fName;

    qInfo()<<"Enter fileName";
    std::getline(std::cin,fileName);
    fileName+=".txt";

    QFile file(QString::fromStdString(fileName));
    if(file.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        // QByteArray data("Testing");
        QByteArray data;
        QString sysTime=QDateTime::currentDateTime().toString();
        while(true){
            qInfo()<<"Enter your firstName (exit): ";
            std::getline(std::cin,fName);

            if(fName=="exit")
                break;
        data.append(sysTime.toLocal8Bit());
        data.append(" - ");
        data.append(fName);


        }
        QTextStream stream(&file);
        stream << data;
        // file.write(data);
        qInfo()<<"Wrote to the file";
        file.close(); //close the the file reading
    }else {
        qInfo()<<file.errorString();
    }

    qInfo()<<QDir::currentPath();
    return a.exec();
}
