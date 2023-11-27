#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>
#include <QByteArray>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;

    if(buffer.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        qInfo()<<"Device is open";
        QByteArray data("Hello World");
        for(int i=0;i<5;i++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }

        buffer.seek(0);
        qInfo()<<buffer.readAll();

        //closing the file
        qInfo()<<"Closing the file";
        buffer.close();
    }else {
        qInfo()<<"Cannot read the file";

    return a.exec();
}
