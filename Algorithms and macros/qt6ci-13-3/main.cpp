#include <QCoreApplication>
#include <QRandomGenerator>
#include <QList>

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
    QList<int> list;
    randoms(&list,10);
    qInfo()<<list;

    std::sort(list.begin(),list.end());
    qInfo()<<"Sorted : "<<list;

    std::reverse(list.begin(),list.end());
    qInfo()<<"Reverse : "<<list;
    return a.exec();
}
