#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QUdpSocket>
#include <random>
#include "packetmanager.h"
//
#include <QDebug>
//

class Connection : public QObject
{
    Q_OBJECT
public:
    explicit Connection(QObject *parent = nullptr);
    ~Connection();
    bool binding(QHostAddress addr);
    void send(QByteArray datagram);
    void sendSystemData(quint8 id);


private:
    QUdpSocket *clientSocket;
    PacketManager *objPackManager;
    QHostAddress serverAddr;
    quint16 serverPort;
    bool fStatusConnect = false; //Флаг isOnline
    quint16 myPort = 0;


private slots:
    void connectWait(QHostAddress addr, quint16 port);
    void sendWait(QString datagram);
    void disconnectWait();
    QString incomingConnection();

signals:
    void datagramToInterface(QString(datagram));
    void connectSetBlock();
};

#endif // CONNECTION_H
