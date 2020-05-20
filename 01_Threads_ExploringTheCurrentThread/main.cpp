#include <QCoreApplication>
#include <QtDebug>
#include <QThread>
#include <QDateTime>

/* ***
 * Exploring the main thread, threads control the execution
 * think of a thread as "time on the CPU
 * *** */


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"App thread="<<a.thread();
    qInfo()<<"Current thread="<<QThread::currentThread();

    Q_ASSERT(a.thread()==QThread::currentThread());

    qInfo()<<"Is running: "<<QThread::currentThread()->isRunning();
    qInfo()<<"Loop level: "<<QThread::currentThread()->loopLevel();
    qInfo()<<"Stack size value: "<<QThread::currentThread()->stackSize();
    qInfo()<<"Is finished: "<<QThread::currentThread()->isFinished();
    qInfo()<<"Before: "<<QDateTime::currentDateTime().toString(Qt::DateFormat::SystemLocaleLongDate);
    QThread::sleep(5);
    qInfo()<<"After: "<<QDateTime::currentDateTime().toString(Qt::DateFormat::SystemLocaleLongDate);

    return a.exec();
}
