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
    void send(QString message, QHostAddress addr, quint16 port);

private:
    QUdpSocket *mySocket;

private slots:
    void receiveWait(QHostAddress addr, quint16 port);
    QString incomingConnection();

signals:
    void datagramToInterface(QString datagram);
};

#endif // SERVER_H
