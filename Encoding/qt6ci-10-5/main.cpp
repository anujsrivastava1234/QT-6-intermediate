#include <QCoreApplication>
#include <QByteArray>
#include <QFile>

QString makeString()
{
    QString data;
    data.append("Unicode Test\r\n");

    for (int i = 0; i < 10; i++) {
        data.append("Hello\r\n");
    }

    return data;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString data=makeString();
    QByteArray bytes(data.toUtf8());
    QByteArray encoded=bytes.toHex();
    QByteArray decoded=QByteArray::fromHex(encoded);

    qInfo()<<"Encoded : "<<encoded;
    qInfo()<<"------------------------";
    qInfo()<<"Decoded : "<<decoded;

    QFile file("data.txt");

    if(file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf16);

        stream<<bytes;
        stream.flush();
        file.close();
    }
    else {
        qInfo()<<file.errorString();
    }

    qInfo()<<"Done";


    return a.exec();
}
