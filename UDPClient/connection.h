#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QUdpSocket>
#include <random>
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
    void send(QByteArray datagram, QHostAddress addr, quint16 port);

private:
    QUdpSocket *clientSocket;
    bool statusConnect = false;
    quint16 myPort = 0;

private slots:
    void receiveWait(QHostAddress addr, quint16 port);
    void sendWait(QString datagram, QHostAddress addr, quint16 port);
    QString incomingConnection();

signals:
    void datagramToInterface(QString(datagram));
    void receiveSetBlock();
};

#endif // CONNECTION_H
