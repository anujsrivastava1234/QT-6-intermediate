#include <QCoreApplication>
#include <QDebug>
#define add(a,b) a+b

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo()<<add(1,2);q
    return a.exec();
}
