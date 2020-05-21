#include <QCoreApplication>
#include <QtDebug>
#include <QThread>
#include <QTimer>
#include <QSharedPointer>
#include "test.h"

static QSharedPointer<QThread> sharedPointer;

void timeout()
{
    if(!sharedPointer.isNull())
    {
        qInfo()<<"We are stopping the thread."<<QThread::currentThread();
        sharedPointer.data()->quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"The application thread is "<<a.thread();
    qInfo()<<"The current thread is "<<QThread::currentThread();

    test t;
    qInfo()<<"The thread of running the instance of the test class "<<t.thread();

    /* *** create a new thread and move our object to the new thread *** */
    QThread qThread;
    sharedPointer.reset(&qThread);
    t.moveToThread(&qThread);
    qInfo()<<"The NEW thread of running the instance of the test class :"<<t.thread();

    t.start();
    qInfo()<<"Check the status of the thread where the object t is running: "<<qThread.isRunning();

    /* *** start the thread object *** */
    qThread.start();


    /* *** start a QTimer() object and execute some method with the object *** */
    QTimer qTimer;
    qTimer.singleShot(5000,&timeout);

    return a.exec();
}
