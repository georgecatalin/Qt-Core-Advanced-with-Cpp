#include <QCoreApplication>
#include <QtDebug>
#include <QSharedPointer>
#include <QTimer>
#include "myclass.h"

static QSharedPointer<myclass> sharedPointer;

void timeout()
{
    if(!sharedPointer.isNull())
    {
        qInfo()<<"Timeout stopping thread";
        sharedPointer.data()->quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myclass qThread;
    sharedPointer.reset(&qThread); //Resets the shared pointer and points it to the address of qThread object instead

    qThread.start();

    /* *** start an instance of  QTimer() class and assign a function for the action *** */
    QTimer qTimer;
    qTimer.singleShot(5000,&timeout);  //calls a slot after a given time interval.



    return a.exec();
}
