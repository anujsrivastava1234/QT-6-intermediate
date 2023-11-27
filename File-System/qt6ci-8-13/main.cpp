#include <QCoreApplication>
#include <QFile>

bool write(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        qInfo()<<file.errorString();
        return false;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_5);

    int age=45;
    QString name="Anuj";
    double weight=180.35;

    qInfo()<<"Writting file";
    stream<<age<<name<<weight;

    if(!file.flush())
    {
        qInfo()<<file.errorString();
        file.close();
        return false;
    }

    qInfo()<<"Closing file";
    file.close();
    return true;
}

bool read(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qInfo()<<"Unable to read the file";
        return false;
    }

    QDataStream stream(&file);
    if(stream.version() != QDataStream::Qt_6_6){
        qInfo()<<"Wrong file version";
        file.close();
        return false;
    }
    int age;
    QString name;
    double weight;

    stream>>age>>name>>weight;

    qInfo()<<"Age : "<<age;
    qInfo()<<"Name : "<<name;
    qInfo()<<"Weight : "<<weight;

    file.close();
    return true;

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString filename="test.txt";
    if(write(filename)) read(filename);
    return a.exec();
}
