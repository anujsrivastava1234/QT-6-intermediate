#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <iostream>

void list(QDir &root)
{
    qInfo()<<"------------- Listing --------------";
    foreach (QFileInfo fi, root.entryInfoList(QDir::Filter::Dirs,QDir::Name)) {
        if(fi.isDir()){
            qInfo()<<fi.absoluteFilePath();
        }

    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir dir(QCoreApplication::applicationDirPath());
    qInfo()<<dir.dirName();
    qInfo()<<dir.absolutePath();
    dir.cdUp();
    qInfo()<<dir.absolutePath();
    list(dir);
    std::string filename;
    qInfo()<<"Enter the filename to file created";
    std::getline(std::cin,filename);
    dir.mkdir(QString::fromStdString(filename));
    list(dir);

    //Removing the directory
    qInfo()<<"Enter the filename to be removed";
    std::getline(std::cin,filename);
    dir.rmdir(QString::fromStdString(filename));
    list(dir);

    return a.exec();
}
