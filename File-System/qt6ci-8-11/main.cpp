#include <QCoreApplication>
#include <QFile>
#include <QByteArray>

void readLines(QFile &file)
{
    if(!file.isReadable()) return;
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo()<<file.readLine();
    }
}

void readchunks(QFile &file)
{
    if(!file.isReadable()) return;
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo()<<file.read(25);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename="test.txt";

    QFile file(filename);
    if(file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        readLines(file);

        qInfo()<<"-----------------------------------";

        readchunks(file);

        file.close();
    }else {
        qInfo()<<file.errorString();
    }
    return a.exec();
}
