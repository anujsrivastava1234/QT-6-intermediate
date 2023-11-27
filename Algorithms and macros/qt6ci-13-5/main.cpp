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
    QList<int> list1;
    randoms(&list1,10);

    QList<int> list2;

    qInfo()<<"List 1 : "<<list1;
    qInfo()<<"List 2 : "<<list2;

    qInfo()<<"Copying...";
    list2.resize(list1.size());
    std::copy(list1.begin(),list1.end(),list2.begin());
    qInfo()<<"List 1 : "<<list1;
    qInfo()<<"List 2 : "<<list2;
    qInfo()<<std::equal(list1.begin(),list1.end(),list2.begin());

    return a.exec();
}
