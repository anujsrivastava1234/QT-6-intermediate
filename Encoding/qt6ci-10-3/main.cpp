#include <QCoreApplication>
#include <QByteArray>
#include <QFile>
#include <QRandomGenerator>

QString makeString()
{
    QString data;
    data.append("Unicode Test\n\r");

    for(int i=0;i<10;i++)
    {
        int number=QRandomGenerator::global()->bounded(100);
        data.append(QChar(number));
    }

    return data;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString data=makeString();

    QFile file("data.txt");

    if(file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf16);

        stream<<data;
        stream.flush();

        file.close();
    }else{
        qInfo()<<file.errorString();
    }

    qInfo()<<"Done";
    qInfo()<<"UTF16"<<data;
    qInfo()<<"UTF8"<<data.toUtf8();
    qInfo()<<"ASCII"<<data.toLatin1();
    return a.exec();
}
