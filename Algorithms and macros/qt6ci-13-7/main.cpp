#include <QCoreApplication>
#include <QDebug>
#include <QMap>

typedef QMap<QString,int> People;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    People p;
    p.insert("Hello ",1);
    p.insert("World",2);
    p.insert("todo",3);

    foreach (auto k, p.keys()) {
        qInfo()<<k<<p[k];
    }
    return a.exec();
}
