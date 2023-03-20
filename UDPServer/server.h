#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    bool bind(QHostAddress addr, quint16 port);
    void send(QByteArray msg, QHostAddress addr, quint16 port);
    void closeSocket();

private:
    QUdpSocket *mySocket;

private slots:
    void receiveWait(QHostAddress addr, quint16 port);
    void endReceiveWait();
    void sendWait(QString datagram, QHostAddress addr, quint16 port);
    QString incomingConnection();

signals:
    void datagramToInterface(QString datagram);
};

#endif // SERVER_H
