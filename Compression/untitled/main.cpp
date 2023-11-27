#include <QCoreApplication>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // QByteArray data("Test\nTest\nTest\nTest\nTest\nTest\nTest\nTest\nTest\nTest\nTest\nTest");
    QByteArray data("Hello World 123");

    QByteArray encoded=qCompress(data);
    QByteArray decoded=qUncompress(encoded);

    qInfo()<<"Encoded : "<<encoded.size();
    qInfo()<<"Decompressed : "<<decoded.size();
    return a.exec();
}
