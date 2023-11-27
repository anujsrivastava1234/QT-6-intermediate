#include <QCoreApplication>
#include <QSysInfo>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSysInfo sys;

    qInfo()<<"System Info";
    qInfo()<<"Boot id : "<<sys.bootUniqueId();
    qInfo()<<"Build : "<<sys.buildAbi();
    qInfo()<<"Cpu : "<<sys.currentCpuArchitecture();
    qInfo()<<"Kernel : "<<sys.kernelType();
    qInfo()<<"Version : "<<sys.kernelVersion();
    qInfo()<<"Host : "<<sys.machineHostName();
    qInfo()<<"Product : "<<sys.prettyProductName();
    qInfo()<<"Type : "<<sys.productType();
    qInfo()<<"Version : "<<sys.productVersion();

#ifdef Q_OS_LINUX
    qInfo()<<"Linux code here";
#elif defined(Q_OS_WIN)
    qInfo()<<"Windows code here";
#elif defined(Q_OS_MACX)
    qInfo()<<"Mac code here";
#else
    qInfo()<<"Unknown code here";
    return a.exec();

#endif
}
