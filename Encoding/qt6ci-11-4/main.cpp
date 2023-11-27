#include <QCoreApplication>
#include <QFile>

bool makeFile(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        QByteArray data;
        for(int i = 0 ; i < 100 ; i++)
        {
            data.append(QString::number(i).toUtf8() + "\r\n");
        }

        file.write(data);
        qInfo()<<data;
        file.close();

        return true;
    }

    return false;
}

QByteArray getHeader()
{
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFile,QString newFile)
{
    QFile oFile(originalFile);
    QFile nFile(newFile);
    QByteArray header=getHeader();

    if(!oFile.open(QIODevice::OpenModeFlag::ReadOnly)) return false;
    if(!nFile.open(QIODevice::OpenModeFlag::WriteOnly)) return false;
    int size=1024;

    while(!oFile.atEnd())
    {
        QByteArray buffer=oFile.read(size);
        QByteArray compressed=qCompress(buffer,9);
        nFile.write(header);
        nFile.write(compressed);
    }

    oFile.close();
    nFile.close();
    qInfo()<<"Finised Compression";
    return true;
}

bool decompressFile(QString originalFile,QString newFile)
{
    QFile oFile(originalFile);
    QFile nFile(newFile);
    QByteArray header=getHeader();

    if(!oFile.open(QIODevice::OpenModeFlag::ReadOnly)) return false;
    if(!nFile.open(QIODevice::OpenModeFlag::WriteOnly)) return false;
    int size=1024;

    QByteArray buffer=oFile.peek(size);
    if(!buffer.startsWith(header))
    {
        qCritical()<<"We did not create this";
        oFile.close();
        nFile.close();
        return false;
    }

    //Find the position header
    oFile.seek(header.length());

    while(!oFile.atEnd())
    {
        buffer=oFile.peek(size);
        qint64 index=buffer.indexOf(header);
        qDebug()<<"Head found at : "<<index;

        if(index > -1)
        {
            //We have a header
            qint64 maxBytes=index;
            qInfo()<<"Reading : "<<maxBytes;
            buffer=oFile.read(maxBytes);
            oFile.read(header.length());
        }else {
            qInfo()<<"Read all no header";
            buffer=oFile.readAll();
        }
        QByteArray decompress=qUncompress(buffer);
        nFile.write(decompress);
        nFile.flush();
    }

    oFile.close();
    nFile.close();
    return true;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString originalFile="original.txt";
    QString compressedFile="compressed.txt";
    QString decompressedFile="decompressed.txt";

    if(makeFile(originalFile)){
        qInfo()<<"Original Created";
        if(compressFile(originalFile,compressedFile))
        {
            qInfo()<<"File compressed";
            if(decompressFile(compressedFile,decompressedFile))
            {
                qInfo()<<"File decompressed";
            }else {
                qInfo()<<"Could not decompress the file";
            }
        }else {
            qInfo()<<"Could not compressed";
        }
    }
    return a.exec();
}
