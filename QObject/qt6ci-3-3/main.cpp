#include <QCoreApplication>
#include "test.h"

void notifications()
{
    Test producer;
    producer.setObjectName("Producer");

    Test reciever;
    reciever.setObjectName("Reciver");

    qDebug()<<&producer;
    qDebug()<<&reciever;

    QObject::connect(&producer,&Test::alarm,&reciever,&Test::wake);

    producer.testing();
    reciever.wake("Ok");
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    notifications();
    return a.exec();
}
