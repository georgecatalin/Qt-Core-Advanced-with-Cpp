#include "counter.h"

counter::counter(QObject *parent) : QObject(parent)
{

}

void counter::start()
{
    for (int i=0;i<20;i++)
    {
        qInfo()<<QThread::currentThread()->objectName()<<" = "<<i;
        auto myValue=static_cast<unsigned long>(QRandomGenerator::global()->bounded(1000));
        QThread::currentThread()->msleep(myValue);
    }

    QThread::currentThread()->quit();
}
