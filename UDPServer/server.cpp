#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    mySocket = new QUdpSocket;
    objPackManager = new PackManager;
    quint16 port = 100;
    this->bind(QHostAddress::LocalHost, port);
}

Server::~Server()
{
    delete objPackManager;

    mySocket->close();
    delete mySocket;
}

bool Server::bind(QHostAddress addr, quint16 port)
{
    connect(mySocket, SIGNAL(readyRead()), this, SLOT(incomingConnection()));
    int status = mySocket->bind(addr, port);
        if(status == true)
            return true;
        else
            return false;
}

void Server::send(QByteArray datagram, QHostAddress addr)
{
    qDebug() << "\nПакет № 5 отправлен ->" << datagram << "Длинна в байтах:" << datagram.size() << "qDebug";
    mySocket->writeDatagram(datagram, addr, senderPort);
}

void Server::sendWaitMsg(QString datagram, QHostAddress addr) //Не тестировалось
{
    QByteArray data = datagram.toUtf8();
    quint8 id = 5; //id msgPack
    QByteArray completeDatagram = objPackManager->buildPack(id, data.size(), data); //Секция возвращает готовую датаграмму id + length + data
    this->send(completeDatagram, addr);
}

QString Server::incomingConnection() //ХЕНДШЕЙК все же нужен чтоб сервер понимал что к нему хотят конектится 28.5.23 14:27
{
    QByteArray datagram;
    datagram.resize(mySocket->pendingDatagramSize());
    mySocket->readDatagram(datagram.data(), datagram.size(), &senderAddr, &senderPort);

    if(!QString(datagram).isEmpty()) {

        if(objPackManager->takeID(datagram) == 0){
            qDebug() << "\nПакет № 0 пришел <-";
            quint8 id = 3;
            QByteArray completeDatagram = objPackManager->buildPack(id);
            qDebug() << "\nПакет № 3 отправлен ->" << completeDatagram << "Длинна в байтах:" << completeDatagram.size() << "qDebug";
            mySocket->writeDatagram(completeDatagram, senderAddr, senderPort);
            //Отправка packSendConn
        }

        if(objPackManager->takeID(datagram) == 1){
            qDebug() << "\nПакет № 1 пришел <-";
            //Отключение клиента
        }

        if(objPackManager->takeID(datagram) == 2){
            qDebug() << "\nПакет № 2 пришел <-" << datagram << "Длинна в байтах:" << datagram.size() << "qDebug";
            emit datagramToInterface(QString(objPackManager->takeReleaseData(datagram))); //Отправляем сообщение из сокета в интерфейс
        }
//        if(){
//            другие релизации
//        }
//        ...
    }



    return QString(datagram);
}

