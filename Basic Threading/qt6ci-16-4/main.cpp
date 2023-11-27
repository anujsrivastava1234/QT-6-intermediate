#include <QCoreApplication>
#include <QThread>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread *thread=thread->currentThread();
    thread->setObjectName("Main Thread");
    qInfo()<<"Starting..."<<thread;

    for (int i = 0; i< 10; i++) {
        qInfo()<<i<<"on"<<thread;
    }

    qInfo()<<"Finsihed";

    return a.exec();
}
