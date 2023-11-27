#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    this->setObjectName("Test");
    qInfo()<<this<<"Constructed";
}

Test::~Test()
{
    qInfo()<<this<<"Deconstructed";
}
