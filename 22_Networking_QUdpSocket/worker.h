#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QUdpSocket>
#include <QNetworkDatagram>

class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr);

signals:

public slots:
    void start();
    void stop();
    void timeout();
    void readyRead();
    void broadcast();

private:
    QUdpSocket qUdpSocket;
    QTimer qTimer;

    /* *** Do not use ports <1024 because these are "admin ports"/"special services ports" used in special services like HTTP, FTP, POP3, SMTP
     * and you are going to need root or admin rights to access these
     * *** */
    quint16 port=2020;

};

#endif // WORKER_H
