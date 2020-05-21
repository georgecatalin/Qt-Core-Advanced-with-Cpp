#include "myclass.h"

myclass::myclass(QObject *parent) : QThread(parent)
{

}

void myclass::quit()
{
    ok=false;
    QThread::quit();
}

void myclass::run()
{
    ok=true;
    for (int i=0;i<1000;i++)
    {
        qInfo()<<i;
        this->sleep(1);
        /* *** this is bad because code becomes unpredictable because control can come from anywhere *** */

        /* *** example of potential bad situation *** */
        if (!ok) break;

    }

    qInfo()<<"Finished....";
}
