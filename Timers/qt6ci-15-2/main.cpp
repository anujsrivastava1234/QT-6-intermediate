#include <QCoreApplication>
#include <QTimer>
#include "test.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Test t;
    t.doStuff();
    return a.exec();
}
