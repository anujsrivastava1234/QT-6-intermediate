#include <QCoreApplication>
#include <QFile>

void write(QFile &file)
{
    if(!file.isWritable())
    {
        qInfo()<<"Unable to write the file";
        return ;
    }

    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::LastEncoding);

    stream.seek(file.size());

    for(int i=0;i<5;i++)
    {
        stream<<QString::number(i)<<"-Item\r\n";
    }

    stream.flush();
    qInfo()<<"File Written";
}

void read(QFile &file)
{
    if(!file.isReadable())
    {
        qInfo()<<"Unable to read the file";
        return;
    }

    QTextStream stream(&file);
    stream.seek(0);
    while(!stream.atEnd())
    {
        qInfo()<<stream.readLine();
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename="test.txt";
    QFile file(filename);

    if(file.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        //setting up the encdoing
        QTextStream stream(&file);
        qInfo()<<"Encoding : "<<stream.encoding();
        write(file);
        read(file);
        file.close();
    }else {
        qInfo()<<file.errorString();
    }
    return a.exec();
}
