#include <QCoreApplication>
#include <QFile>
#include <QDateTime>
#include <QTemporaryFile>
#include <QDataStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    // QFile file(filename);
    QTemporaryFile file;

    if(file.open())
    {
        qInfo()<<"File:"<<file.fileName();
        QByteArray dataout("Hello World");
        file.write(dataout);
        file.flush();
        file.seek(0);
        qInfo()<<file.readAll();
        file.close();

    }
    else {
        qInfo()<<file.errorString();
    }
    return a.exec();
}
