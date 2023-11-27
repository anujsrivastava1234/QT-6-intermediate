#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{
    qInfo()<<"Constructed"<<this<<" on "<<QThread::currentThread();
}

Task::~Task()
{
    qInfo()<<"Deconstrcuted "<<this <<" on "<<QThread::currentThread();
}

void Task::run()
{
    QThread *thread=QThread::currentThread();

    qInfo()<<"Started"<<thread;
    for(int i=0;i<10;i++)
    {
        qInfo()<<i<<" on "<<thread;
    }
    qInfo()<<"finsihed"<<thread;
}
