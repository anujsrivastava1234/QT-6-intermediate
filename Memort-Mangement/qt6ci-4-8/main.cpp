#include <QCoreApplication>
#include <QSharedPointer>
#include "test.h"

QSharedPointer<Test> getObject(QString name)
{
    QSharedPointer<Test> obj(new Test());
    obj->setObjectName(name);
}

void doWork(QSharedPointer<Test> obj)
{
//    QSharedPointer<Test> sp=getObject("My Object");
    obj=getObject("My Object");
    qInfo()<<"Pointer Data"<<obj.data();
    qInfo()<<"Pointer Info"<<&obj;
}

void test()
{
    QSharedPointer<Test> obj1(new Test());

    qInfo()<<"Pointer Data"<<obj1.data();
    qInfo()<<"Pointer Info"<<obj1;

    doWork(obj1);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
