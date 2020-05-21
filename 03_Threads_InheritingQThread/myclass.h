#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>
#include <QThread>

class myclass : public QThread
{
    Q_OBJECT
public:
    explicit myclass(QObject *parent = nullptr);

signals:

public slots:
    void quit();

protected:
    void run();

private:
    bool ok;

};

#endif // MYCLASS_H
