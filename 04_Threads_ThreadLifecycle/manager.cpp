/* ***
 * The idea of the demonstration is that the class manager() will create multiple threads
 * and each thread will hold an object of the counter() class
 * *** */

#include "manager.h"

manager::manager(QObject *parent) : QObject(parent)
{
    for(int i=0;i<20;i++)
    {
        /* ***
         *   Create a QThread Object:
         * Actually it is happening like this: you create a pointer on the stack (managed memory)  which
         * points to the instantiation of the QThread() class in the heap memory(the huge memory that belongs to
         * the operating system. This is how it happens C++, unlike other languages. And it happens in C++ this memory for the sake of memory efficiency.
         * */
        QThread* qThread=new QThread(this); //we are taking this pointer as a pointer for C++ ish considerations as well. Memory handling efficiency, when this ceases to exis, the derived objects=children vanish as well.
        qThread->setObjectName("Thread "+ QString::number(i));

        qInfo()<<"Created the following thread: "<<qThread->objectName();

        /* ***
         * Next step: I am connection the qThread() object with the manager() object by means of signals and slots
         * qThread() object signal <> manager() object slot
         * If in doubt, and you do not know which are the signals you can use of the QThread() class , then check its official reference on the web at doc.qt.io/..
         *
         * *** */
        connect(qThread,&QThread::started,this,&manager::started);
        connect(qThread,&QThread::finished,this,&manager::finished);

        qListOfThreads.append(qThread);


}}

void manager::start()
{
    qInfo()<<"Starting all threads...";

    foreach (QThread* threadPointer, qListOfThreads)
    {
        qInfo()<<"Starting the following thread: ";threadPointer->objectName();

        /* *** instantiating objects in the class counter *** */
        counter* objCounter=new counter(); //objects that run in a thread should not hold a parent
        objCounter->moveToThread(threadPointer);
        //c->start(); //this will be done in single thread, if used.

        connect(threadPointer,&QThread::started,objCounter,&counter::start);
        threadPointer->start();
    }
}

void manager::started()
{
    QThread* objThread=qobject_cast<QThread*>(sender());

    if(objThread==0) return;

    qInfo()<<"started..."<<objThread->objectName();
}

void manager::finished()
{
    QThread* objThread=qobject_cast<QThread*>(sender());
    if(objThread==0) return;

    qInfo()<<"Finished..."<<objThread->objectName();
}
