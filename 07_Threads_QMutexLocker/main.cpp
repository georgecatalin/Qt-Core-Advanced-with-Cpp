#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include "counter.h"
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    counter myCounter;

    /* *** Instantiate a QMutex() object ("traffic cop") and set it to recursive so that it can be locked and unlocked multiple times *** */
    QMutex mutex(QMutex::Recursive);

    QThreadPool* qThreadPool=QThreadPool::globalInstance();

    /* *** make sure the counter starts at 0 *** */
    qInfo()<<" Counter starts at "<<myCounter.count();

    for(int i=0;i<qThreadPool->maxThreadCount();i++)
    {
        worker* myWorker=new worker(&a,&myCounter,&mutex);
        myWorker->setAutoDelete(true); //we avoid messing up with memory management

        qThreadPool->start(myWorker);
    }

    qThreadPool->waitForDone();
    qInfo()<<"Done, the count is :"<<myCounter.count();

    return a.exec();
}
