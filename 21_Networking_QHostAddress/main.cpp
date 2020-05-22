#include <QCoreApplication>
#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QAbstractSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QHostAddress> myList=QNetworkInterface::allAddresses();

    for(int i=0;i<myList.count();i++)
    {
        QHostAddress qHostAddress=myList.at(i);
        qInfo()<<qHostAddress.toString();

        /* *** Never leaves the box. Only used for development purposes *** */
        qInfo()<<"\t Is this a loopback? "<<qHostAddress.isLoopback();

        /* *** Send to many destinations at once through a special technology *** */
        qInfo()<<"\t Is it multicast?"<<qHostAddress.isMulticast();

        /* *** Get the protocol of communication - it refers to the network layer of the 7-stages OSI model *** */
        switch (qHostAddress.protocol())
        {
        case QAbstractSocket::UnknownNetworkLayerProtocol:
            qInfo()<<"\t Protocol: unknown layer ";
            break;
        case QAbstractSocket::AnyIPProtocol:
            qInfo()<<"\t Protocol: Any";
            break;
        case QAbstractSocket::IPv4Protocol:
            qInfo()<<"\t Protocol: IPv4";
            break;
        case QAbstractSocket::IPv6Protocol:
            qInfo()<<"\t Protocol: IPv6";
            break;
        }
    }


    return a.exec();
}
