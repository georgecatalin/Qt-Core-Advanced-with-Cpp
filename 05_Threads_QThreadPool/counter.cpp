#include "counter.h"

//run() will be called by the pool of threads;
void counter::run()
{
    qInfo()<<"Starting..."<<QThread::currentThread();

    for(int i=0;i<10;i++)
    {
        qInfo()<<QThread::currentThread()<<" = "<<i;
        auto myValue=static_cast<int>(QRandomGenerator::global()->bounded(500));
        QThread::currentThread()->msleep(myValue);
    }

    qInfo()<<"Finished..."<<QThread::currentThread();
}
