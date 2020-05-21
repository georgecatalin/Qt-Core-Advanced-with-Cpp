#include "worker.h"


worker::worker(QObject *parent,QStringList* qStringList,QSemaphore* qSemaphore,int position) : QObject(parent)
{
    this->qStringList=qStringList;
    this->qSemaphore=qSemaphore;
    this->position=position;
}

void worker::run()
{
    if (qStringList==nullptr || qSemaphore==nullptr)
    {
        qInfo()<<" Missing pointers";
        return;
    }

    QString t;

}
