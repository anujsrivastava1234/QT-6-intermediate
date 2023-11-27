#include "toy.h"

Toy::Toy(QObject *parent, QString name)
    : QObject{parent}
{
    setObjectName(name);
    qInfo()<<this<<"Constructed";
}

Toy::~Toy()
{
    qInfo()<<this<<"Deconstructed";
}
