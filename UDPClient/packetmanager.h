#ifndef PACKETMANAGER_H
#define PACKETMANAGER_H

#include <QObject>
#include <QDataStream>
#include <QIODevice>
#include <QList>

#include <QDebug>

class PacketManager : public QObject
{
    Q_OBJECT
public:
    explicit PacketManager(QObject *parent = nullptr);

    //Работа с полученными пакетами
    quint8 takeID(QByteArray receivDatagram);
    quint8 takeLength(QByteArray receivDatagram);
    QByteArray takeReleaseData(QByteArray receivDatagram);


    //Сборка пакетов
    QByteArray buildPack(quint8 id, quint8 length, QByteArray data);
    QByteArray buildPack(quint8 id);

private:
    quint8 id;
    quint8 length;
    quint8 packConnection = 0;
    quint8 packDisconnection = 1;
    quint8 packSendMsg = 2;
    quint8 packServerAnswerConn = 3;
    quint8 packServerAnsverDisconn = 4; //Реализовать после многоклиентности и БД
    quint8 packServerAnsverMsg = 5;

    QList<quint8> packets = { packConnection,
                           packDisconnection,
                           packSendMsg,
                           packServerAnswerConn,
                           packServerAnsverDisconn,
                           packServerAnsverMsg };

signals:

};

#endif // PACKETMANAGER_H
