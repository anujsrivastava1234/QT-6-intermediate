#include <QCoreApplication>
#include <QRandomGenerator>
#include <QDebug>

void randoms(QList<int> *list,int max)
{
    list->reserve(max);
    for(int i=0;i<max;i++)
    {
        int value=QRandomGenerator::global()->bounded(1000);
        list->append(value);
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list1;
    randoms(&list1,10);
    qInfo()<<list1;
    return a.exec();
}
