#include <QCoreApplication>
#include "cat.h"
#include "toy.h"
#include <vector>

void test()
{
    int max=5;
    QSharedPointer<Toy> toy(new Toy());
    std::vector<QSharedPointer<Cat>> cats(max);

    for(int i=0;i<5;i++)
    {
        cats[i].reset(new Cat());
        cats[i]->play(toy);
    }

    qInfo()<<"All Cats are done";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
