#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QRandomGenerator>

class counter : public QObject
{
    Q_OBJECT
public:
    explicit counter(QObject *parent = nullptr);

public slots:
    void start();

signals:

};

#endif // COUNTER_H
