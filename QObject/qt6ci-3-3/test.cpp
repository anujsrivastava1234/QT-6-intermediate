#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo()<<this<<"Constructed";
}

Test::~Test()
{
    qInfo()<<this<<"Deconstrcuted";
}

void Test::testing()
{
    QString noise="Wake up!!!";
    emit alarm(noise);
}

void Test::wake(QString noise)
{
    qInfo()<<"From"<<sender()<<noise;
}
