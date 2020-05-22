#include "worker.h"

worker::worker(QObject *parent) : QObject(parent)
{
    /* *** connect the timer to the workers and connect the socket to the worker *** */
    connect(&qTimer,&QTimer::timeout,this,&worker::timeout);

    /* ***  void QTimer::timeout()
     * This signal is emitted when the timer times out.
     * *** */
    connect(&qUdpSocket,&QUdpSocket::readyRead,this,&worker::readyRead);

    qTimer.setInterval(1000);
}

void worker::start()
{
    /* *** verify if binding to the desired port was handled ok and if not, display the error message on the screen *** */
    if(!qUdpSocket.bind(port))
    {
        qInfo()<<"Ooops...I could not bind via UDP to the port "<<port;
        qInfo()<<qUdpSocket.errorString();
        return;
    }

    qInfo()<<"\t Starting UDP on "<<qUdpSocket.localAddress()<<" at port =" <<qUdpSocket.localPort();

    /* ***
     * QHostAddress QAbstractSocket::localAddress() const
     * Returns the host address of the local socket if available; otherwise returns QHostAddress::Null.
     * This is normally the main IP address of the host, but can be QHostAddress::LocalHost (127.0.0.1) for connections to the local host.

     * quint16 QAbstractSocket::localPort() const
     * Returns the host port number (in native byte order) of the local socket if available; otherwise returns 0.
     * *** */

    broadcast();
}

void worker::stop()
{
    qTimer.stop();
    qUdpSocket.close();

    qInfo()<<"Stopped the UDP transmission.";
}

void worker::timeout()
{
    QString date=QDateTime::currentDateTime().toString();
    QByteArray convertDate=date.toLatin1();

    QNetworkDatagram qNetworkDatagram(convertDate,QHostAddress::Broadcast,port); //send data to the destination address marked by broadcast, at its port
    qInfo()<<"\t Send"<<date;

    qUdpSocket.writeDatagram(qNetworkDatagram);
    /* *** pushing the data through your network to your destination address at its intended port as described at line 49 *** */

}

void worker::readyRead()
{
    while(qUdpSocket.hasPendingDatagrams())
    {
        QNetworkDatagram qNetworkDatagram=qUdpSocket.receiveDatagram();
        qInfo()<<"Read: "<<qNetworkDatagram.data()<<"  from"<<qNetworkDatagram.senderAddress()<<" on port"<<qNetworkDatagram.senderPort();
    }
}

void worker::broadcast()
{
    qInfo()<<"Broadcasting...";
    qTimer.start();
}
