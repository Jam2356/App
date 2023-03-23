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

bool Connection::bind(QHostAddress addr)
{
    std::random_device rd; //Cекция генерации порта
    std::mt19937 mt(rd());
    const int min = 1;
    const int max = 64000;
    std::uniform_int_distribution<int> ds(min, max);
    quint16 port = ds(mt);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(incomingConnection()));
    int status = clientSocket->bind(addr, port);
        if(status == true){
            qDebug() <<"Bind!" << "Port: " << port;
            return true;
        }
        else
            return false;
}

void Connection::send(QByteArray datagram, QHostAddress addr, quint16 port)
{
    clientSocket->writeDatagram(datagram, addr, port);
}

void Connection::receiveWait(QHostAddress addr)
{
    this->bind(addr);
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
