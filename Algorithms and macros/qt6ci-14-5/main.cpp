#include <QCoreApplication>
#include <QProcess>

bool test()
{
    QProcess gzip;
    gzip.start("gzip",QStringList()<<"-c");

    if(!gzip.waitForStarted(3000)) return false;

    QByteArray data;
    for(int i=0;i<100;i++)
    {
        QString item="item "+QString::number(i);
        data.append(item.toUtf8());
    }

    gzip.write(data);
    gzip.closeWriteChannel();
    if(!gzip.waitForFinished(3000)) return false;

    QByteArray result=gzip.readAll();

    qInfo()<<"Orignal Data : "<<data.size();
    qInfo()<<"Compressed : "<<result.size();
    qInfo()<<"Data : "<<data;



    return true;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if(test())
    {
        qInfo()<<"Compressed with QZip";
    }else {
        qInfo()<<"Failed to compress";
    }
    return a.exec();
}
