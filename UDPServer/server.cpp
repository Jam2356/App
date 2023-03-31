#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    quint16 port = 100;
    this->bind(QHostAddress::LocalHost, port);
}

Server::~Server()
{
    this->closeSocket();
}
//Сначала получаем порт из интерфейса, потом биндим порт при нажатии кнопки receive,
//если датаграммы есть, то отправляем их в интерфейс с помощью datagramToInterface

bool Server::bind(QHostAddress addr, quint16 port)
{
    mySocket = new QUdpSocket;
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
    delete mySocket;
}

void Server::send(QByteArray datagram, QHostAddress addr)
{
    mySocket->writeDatagram(datagram, addr, senderPort);
}

void Server::sendWait(QString datagram, QHostAddress addr)
{
    this->send(("Server: " + datagram).toUtf8(), addr);
}

QString Server::incomingConnection()
{
    QByteArray datagram;
    datagram.resize(mySocket->pendingDatagramSize());
    mySocket->readDatagram(datagram.data(), datagram.size(), &senderAddr, &senderPort);
    if(ofOnline == false){ //Секция с хендшейк-сообщением обрабатывает c - connection, нужнодобавить d - disconnect
        QStringList check = QString(datagram).split('/');
        qDebug() <<"Хендшейк строка: " << check;
        if(check[0] == "c")
            if(check[1] == senderAddr.toString())
                if(check[2] == QString::number(senderPort))
                {
                    ofOnline = true; //Этот флажок будет лежать в базе данных у каждого клиента, показывает подключен ли в данный момент клиент
                    qDebug() << ofOnline;
                    //Добавление нового пользовател в вектор пользователей с ником check[1]+"/"+check[2]
                }
    } //

    if(!QString(datagram).isEmpty()) {
        emit datagramToInterface(QString(datagram)); //Отправляем сообщение из сокета в интерфейс
    }
    return QString(datagram);
}

