#include <QCoreApplication>
#include <QFile>
#include <QDateTime>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename="Names.txt";

    QFile file(filename);

   if(file.open(QIODevice::OpenModeFlag::ReadOnly)) {
        qInfo()<<"Read All"<<file.readAll();
        file.close();
   }else {
       qInfo()<<file.errorString();
   }
    return a.exec();
}
