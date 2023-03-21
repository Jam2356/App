#include "connection.h"

Connection::Connection(QObject *parent)
    : QObject{parent}
{
    clientSocket = new QUdpSocket;
}

Connection::~Connection()
{
    clientSocket->close();
    delete clientSocket;
}

bool Connection::bind(QHostAddress addr, quint16 port)
{
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(incomingConnection()));
    int status = clientSocket->bind(addr, port+1);
        if(status == true){
            qDebug() <<"Bind!";
            return true;
        }
        else
            return false;
}

void Connection::send(QByteArray datagram, QHostAddress addr, quint16 port)
{
    clientSocket->writeDatagram(datagram, addr, port);
}

void Connection::receiveWait(QHostAddress addr, quint16 port)
{
    this->bind(addr, port);
}

QString Connection::incomingConnection()
{
    QHostAddress senderAddr;
    quint16 senderPort;
    QByteArray datagram;
    datagram.resize(clientSocket->pendingDatagramSize());
    clientSocket->readDatagram(datagram.data(), datagram.size(), &senderAddr, &senderPort);
    if(!QString(datagram).isEmpty()) {
        emit datagramToInterface(QString(datagram)); //Отправляем сообщение из сокета в интерфейс
    }
    return QString(datagram);
}

void Connection::sendWait(QString datagram ,QHostAddress addr, quint16 port)
{
    this->send(("Client: " + datagram).toUtf8(), addr ,port);
}
