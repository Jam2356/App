#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>
#include "buffers.h" //Основной поток сервера будет читать с сокета
#include "connections.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    bool bind(QHostAddress addr, quint16 port);
    void send(QByteArray msg, QHostAddress addr);
    void closeSocket();

private:
    QUdpSocket *mySocket;
    QHostAddress senderAddr;
    quint16 senderPort;

    bool ofOnline = false; //Будет перенесено в базу данных для каждого человека свое

private slots:
    void sendWait(QString datagram, QHostAddress addr);
    QString incomingConnection();

signals:
    void datagramToInterface(QString datagram);
};

#endif // SERVER_H
