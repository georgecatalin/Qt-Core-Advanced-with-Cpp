#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    manager m;
    m.start();

    return a.exec();
}
