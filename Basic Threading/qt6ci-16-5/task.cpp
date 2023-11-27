#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{
    QThread *thread=QThread::currentThread();
    qInfo()<<"Constructed "<<this<<" on "<<thread;
}

Task::~Task()
{
    qInfo()<<"Deconstructed "<<this <<" on "<<QThread::currentThread();
}

void Task::work()
{
    QThread *thread=QThread::currentThread();

    qInfo()<<"Started ...."<<thread;
    for(int i=0;i<10;i++)
    {
        qInfo()<<i<<" on "<<thread;
    }
    qInfo()<<"Finished..."<<thread;
}
