#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QRandomGenerator>
#include <QThread>


class counter : public QRunnable
{
public:
   void run();

};

#endif // COUNTER_H
