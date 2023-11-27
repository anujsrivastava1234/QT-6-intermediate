#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    parent.setObjectName("Parent");

    QObject child;
    child.setObjectName("Child");

    //set the parent
    child.setParent(&parent);

    //getting the parent
    qInfo()<<child.parent();

    //getting the child
    qInfo()<<parent.children();

    foreach (QObject *obj, parent.children()) {
        qInfo()<<obj;
    }
    return a.exec();
}
