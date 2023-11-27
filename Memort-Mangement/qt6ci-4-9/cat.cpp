#include "cat.h"

Cat::Cat(QObject *parent, QString name)
    : QObject{parent}
{
    setObjectName(name);
    qInfo()<<this<<"Constructed";
}

Cat::~Cat()
{
    qInfo()<<this<<"Deconstructed";
}

void Cat::play(QSharedPointer<Toy> toy)
{
    m_toy.swap(toy);
    qInfo()<<this<<"Playing with "<<m_toy.data();
}
