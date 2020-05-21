#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* *** name the current thread as "Main" *** */
    QThread::currentThread()->setObjectName("Main");

    QThreadPool* qThreadPool=QThreadPool::globalInstance();

    qInfo()<<qThreadPool->maxThreadCount()<<" Threads";

    for (int i=0;i<100;i++)
    {
        counter* c=new counter();
        c->setAutoDelete(true);

        qThreadPool->start(c);
    }



    return a.exec();
}
