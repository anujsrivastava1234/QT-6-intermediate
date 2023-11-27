#include <QCoreApplication>


void testPointer(QObject *obj)
{
    qInfo()<<obj;
}

void testAddress(QObject &obj)
{
    qInfo()<<&obj;
}

void testing(QObject *obj)
{
    qInfo()<<&obj;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QObject person;
    person.setObjectName("Person");

    testPointer(&person);
    testing(&person);
    return a.exec();
}
