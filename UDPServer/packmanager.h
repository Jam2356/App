#ifndef PACKMANAGER_H
#define PACKMANAGER_H

#include <QObject>
#include <QDataStream>
#include <QIODevice>
#include <QList>

#include <QDebug>

class PackManager : public QObject
{
    Q_OBJECT
public:
    explicit PackManager(QObject *parent = nullptr);
    //Работа с полученными сообщениями:
    quint8 takeID(QByteArray datagram);
    quint8 takeLength(QByteArray datagram);
    QByteArray takeReleaseData(QByteArray receivDatagram);
    //Сборка пакетов:
    QByteArray buildPack(quint8 id, quint8 length, QByteArray data);
    QByteArray buildPack(quint8 id);

private:
    quint8 id;
    quint8 length;
    quint8 packRecConnection = 0;
    quint8 packRecDisconnection = 1;
    quint8 packServerAnswerConn = 3;
    quint8 packSendDisconn = 4; //Реализовать после многоклиентности и БД
    quint8 packSendMsg = 5;
    quint8 packRecMsg = 2;

    QList<quint8> packets = { packRecConnection,
                           packRecDisconnection,
                           packRecMsg,
                           packServerAnswerConn,
                           packSendDisconn,
                           packSendMsg };
};

#endif // PACKMANAGER_H
