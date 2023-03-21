#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    mySocket = new QUdpSocket;
}

Server::~Server()
{
    mySocket->close();
    delete mySocket;
}
//Сначала получаем порт из интерфейса, потом биндим порт при нажатии кнопки receive,
//если датаграммы есть, то отправляем их в интерфейс с помощью datagramToInterface

bool Server::bind(QHostAddress addr, quint16 port)
{
    connect(mySocket, SIGNAL(readyRead()), this, SLOT(incomingConnection()));
    int status = mySocket->bind(addr, port);
        if(status == true)
            return true;
        else
            return false;
}

void Server::closeSocket()
{
    mySocket->close();
}

void Server::send(QByteArray datagram, QHostAddress addr, quint16 port)
{
    mySocket->writeDatagram(datagram, addr, port+1);
}

void Server::sendWait(QString datagram ,QHostAddress addr, quint16 port)
{
    this->send(("Server: " + datagram).toUtf8(), addr ,port);
}

void Server::receiveWait(QHostAddress addr, quint16 port)
{
    this->bind(addr, port);
}

void Server::endReceiveWait()
{
    this->closeSocket();
}

QString Server::incomingConnection()
{
    QHostAddress senderAddr;
    quint16 senderPort;
    QByteArray datagram;
    datagram.resize(mySocket->pendingDatagramSize());
    mySocket->readDatagram(datagram.data(), datagram.size(), &senderAddr, &senderPort);
    if(!QString(datagram).isEmpty()) {
        emit datagramToInterface(QString(datagram)); //Отправляем сообщение из сокета в интерфейс
    }
    return QString(datagram);
}

