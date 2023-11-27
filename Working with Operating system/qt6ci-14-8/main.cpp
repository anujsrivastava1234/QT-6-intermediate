#include <QCoreApplication>
#include <QProcess>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo()<<"Args";
    for(int i=0;i<argc;i++)
    {
        qInfo()<<argv[i];
    }

    QTimer::singleShot(3000,&a,SLOT(quit()));

    int code=a.exec();
    qInfo()<<"Code : "<<code;
    return a.exec();
}
