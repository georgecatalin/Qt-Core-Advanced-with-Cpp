#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRunnable>
#include <QSemaphore>


class worker : public QObject,public QRunnable
{
    Q_OBJECT
public:
   explicit worker(QObject *parent = nullptr,QStringList* data=nullptr, QSemaphore* qSemaphore=nullptr,int position=-1);
    void run();
signals:

private:
        QStringList* qStringList;
        QSemaphore* qSemaphore;
        int position;

};

#endif // WORKER_H
