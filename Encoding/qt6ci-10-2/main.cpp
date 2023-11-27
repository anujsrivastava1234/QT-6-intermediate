#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QRandomGenerator>
#include <QByteArray>

QString makeString()
{
    QString data;
    data.append("Unicode Test\r\n");

    for(int i = 0 ; i < 10 ; i++)
    {
        int number=QRandomGenerator::global()->bounded(1000);
        data.append(QChar(number));
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data=makeString();
    qInfo()<<data;

    QFile file("data.txt");
    if(file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf8);

        stream<<data;
        stream.flush();


        file.close();
    }else {
        qInfo()<<file.errorString();
    }

    qInfo()<<"Done";
    qInfo()<<"UTF8"<<data;
    qInfo()<<"ASCII"<<data.toLatin1();
    return a.exec();
}
