#include <QCoreApplication>
#include <QTimer>
#include <QProcess>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess proc;
    proc.start("gedit");

    QTimer::singleShot(3000,&proc,&QProcess::terminate);

    return a.exec();
}
