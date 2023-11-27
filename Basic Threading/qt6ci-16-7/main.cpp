#include <QCoreApplication>
#include <QtConcurrent>
#include <QThread>
#include <QProcess>
#include <QTimer>
#include <QFile>
int Test()
{
    QThread *thread=QThread::currentThread();
    int value=0;

    QString filename="output.txt";
    QFile file(filename);

    if(file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        QTextStream stream(&file);
        for(int i=0;i<10;i++)
        {
            qInfo()<<i<<" on "<<thread;
            value=value+i;
            stream<<QString::number(value)+QString::number(i)<<"\r\n";
        }

        stream.flush();
        file.close();

    }else {
        qInfo()<<file.errorString();
    }

    qInfo()<<"Started..."<<QThread::currentThread();

    qInfo()<<"Finsihed..."<<thread;

    return value;
}

void openApp(QProcess *proc)
{

    proc->start("gedit");
    QTimer::singleShot(3000,[proc](){
        proc->terminate();
        proc->waitForFinished();
        delete proc;
    });

}

void call()
{
    QProcess *proc=new QProcess;
    openApp(proc);
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFuture<int> future1=QtConcurrent::run(&Test);
    QFuture<int> future2=QtConcurrent::run(&Test);
    QFuture<int> future3=QtConcurrent::run(&Test);

    qInfo()<<"Value1 : "<<future1.result();
    qInfo()<<"Value2 : "<<future2.result();
    qInfo()<<"Value3 : "<<future3.result();


    QFuture<void> futureApp=QtConcurrent::run(&call);

    // return a.exec();
}
