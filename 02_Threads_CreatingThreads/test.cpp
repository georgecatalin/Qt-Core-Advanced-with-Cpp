#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::timeout()
{
    qInfo()<<QDateTime::currentDateTime().toString(Qt::DateFormat::SystemLocaleLongDate)<<QThread::currentThread();
}

void test::start()
{
    qTimer.setInterval(1000);
    qTimer.start();

    connect(&qTimer,&QTimer::timeout,this,&test::timeout);

}


