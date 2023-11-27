#include <QCoreApplication>
#include <QByteArrayView>
#include <QByteArray>

void display(QByteArrayView &view)
{
    qInfo()<<view;

    for(auto c:view){
        qInfo()<<c;qt
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray arrayView("Hello this is a test");
    QByteArrayView view(arrayView);

    display(view);

    return a.exec();
}
