#include <QCoreApplication>
#include <QDebug>
#include <QThreadPool>
#include <QSemaphore>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
