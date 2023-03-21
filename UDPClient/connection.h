#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QUdpSocket>
//
#include <QDebug>
//

class Connection : public QObject
{
    Q_OBJECT
public:
    explicit Connection(QObject *parent = nullptr);
    ~Connection();
    bool bind(QHostAddress addr, quint16 port);
    void send(QByteArray datagram, QHostAddress addr, quint16 port);

private:
    QUdpSocket *clientSocket;

private slots:
    void receiveWait(QHostAddress addr, quint16 port);
    void sendWait(QString datagram, QHostAddress addr, quint16 port);
    QString incomingConnection();

signals:
    void datagramToInterface(QString(datagram));
};

#endif // CONNECTION_H
