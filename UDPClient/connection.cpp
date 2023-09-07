#include "connection.h"

Connection::Connection(QObject *parent)
    : QObject{parent}
{
    clientSocket = new QUdpSocket;
    objPackManager = new PacketManager;
}

Connection::~Connection()
{
    delete objPackManager;

    clientSocket->close();
    delete clientSocket;
}

bool Connection::binding(QHostAddress addr)
{
    std::random_device rd; //Cекция генерации порта
    std::mt19937 mt(rd());
    const int min = 1;
    const int max = 64000;
    std::uniform_int_distribution<int> ds(min, max);
    myPort = ds(mt);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(incomingConnection()));
    int status = clientSocket->bind(addr, myPort);
        if(status == true)
        {
            qDebug() <<"Успешный Bind!" << "Ваш порт: " << myPort;
            return true;
        }
        else
            return false;
}

void Connection::send(QByteArray datagram)
{
    qDebug() << "\nПакет № 2 отправлен ->" << datagram << "Длинна в байтах:" << datagram.size() << "qDebug";
    clientSocket->writeDatagram(datagram, serverAddr, serverPort);
}

void Connection::sendSystemData(quint8 id)
{
    QByteArray systemData = objPackManager->buildPack(id);
    qDebug() << "\nПакет №" << id << " отправлен ->" << systemData << "Длинна в байтах:" << systemData.size() << "qDebug";
    clientSocket->writeDatagram(systemData, serverAddr, serverPort);
}

void Connection::connectWait(QHostAddress addr, quint16 port)
{
    this->binding(addr);
    serverAddr = addr;
    serverPort = port;
    this->sendSystemData(0); //Первое сообщение хендшейк
    emit connectSetBlock();
}

void Connection::disconnectWait()
{
    this->sendSystemData(1); //Отправляем запрос на отсоединение от сервера
}

void Connection::sendWait(QString datagram)
{
    if(fStatusConnect)
    {
        QByteArray data = datagram.toUtf8();
        quint8 id = 2;
        QByteArray completeDatagram = objPackManager->buildPack(id, data.size(), data);
        this->send(completeDatagram);
    }
}

QString Connection::incomingConnection()
{
    QByteArray datagram;
    datagram.resize(clientSocket->pendingDatagramSize());
    clientSocket->readDatagram(datagram.data(), datagram.size(), &serverAddr, &serverPort);
    if(!QString(datagram).isEmpty())
    {
        if(objPackManager->takeID(datagram) == 3)
        {
            qDebug() << "\nПакет № 3 пришел <-" << datagram << "Длинна в байтах:" << datagram.size() << "qDebug";
            fStatusConnect = true;
        }

        if(objPackManager->takeID(datagram) == 5)
        {
            qDebug() << "\nПакет № 5 пришел <-" << datagram << "Длинна в байтах:" << datagram.size() << "qDebug";
            emit datagramToInterface(QString(objPackManager->takeReleaseData(datagram))); //Отправляем сообщение из сокета в интерфейс
        }
//        if(){
//            другие релизации
//        }
//        ...
    }
    return QString(datagram);
}


