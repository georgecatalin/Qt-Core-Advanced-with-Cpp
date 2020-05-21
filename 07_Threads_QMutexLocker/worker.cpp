#include "worker.h"

worker::worker(QObject *parent,  counter *myCounter, QMutex *qMutex) : QObject(parent),QRunnable()
{
    this->myCounter=myCounter;
    this->qMutex=qMutex;
}

void worker::run()
{
    if(myCounter==nullptr) return;

    qInfo()<<this<<" Starting";

    for (int i=0;i<100;i++)
    {
       QMutexLocker locker(qMutex);

       myCounter->increment();
       qInfo()<<this<<" Count: "<<myCounter->count();

       myCounter->decrement();
    }

    qInfo()<<this<<" Finished";
}
