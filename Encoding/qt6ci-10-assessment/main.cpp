#include <QCoreApplication>
#include <QFile>

QString makeString()
{
    QString data;
    data.append("Hello my name is anuj");

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
    qInfo()<<"Decoded : "<<decoded;
    return a.exec();
}
