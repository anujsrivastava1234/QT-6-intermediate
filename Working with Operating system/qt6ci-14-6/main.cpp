#include <QCoreApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo()<<"Starting ...";
    QProcess proc;
    proc.execute("xed",QStringList()<<"https://doc.qt.io/qt-6/qmlapplications.html");
    qInfo()<<"Exiting ..."<<proc.exitCode();
    return a.exec();
}
