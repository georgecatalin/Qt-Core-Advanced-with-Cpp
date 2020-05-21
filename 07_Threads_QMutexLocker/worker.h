#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRunnable>
#include <QMutex>
#include <QMutexLocker>
#include <QRandomGenerator>
#include "counter.h"

class worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr,counter* counter=nullptr, QMutex* qMutex=nullptr);
    void run();

signals:

private:
    counter* myCounter;
    QMutex* qMutex;

};

#endif // WORKER_H
