#include <QCoreApplication>
#include <QRandomGenerator>
#include <QList>
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

    qInfo()<<"List1 : "<<list1;

    QList<int> list2;
    randoms(&list2,10);

    qInfo()<<"List2 : "<<list2;

    list1.fill(9);
    list2.fill(9);

    qInfo()<<"List1 : "<<list1;
    qInfo()<<"List2 : "<<list2;

    qInfo()<<std::equal(list1.begin(),list1.end(),list2.begin());



    return a.exec();
}
