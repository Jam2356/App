#include "packetmanager.h"

PacketManager::PacketManager(QObject *parent)
    : QObject{parent}
{

}

//Работа с полученными пакетами
quint8 PacketManager::takeID(QByteArray datagram)
{
    for (int i = 0; i < packets.size(); i++) {
        if(datagram[0] == packets[i]) {
            return id = packets[i];
        }
    }
    return 100;
}

quint8 PacketManager::takeLength(QByteArray datagram) //Можно выитать из .size() длинну заголовка тоесть 2
{
    return length = datagram[1];
}

QByteArray PacketManager::takeReleaseData(QByteArray receivDatagram)
{
    QByteArray releaseDatagram;
    int s = receivDatagram.size() - 2;
    releaseDatagram = receivDatagram.mid(2, s);
    return releaseDatagram;
}

//Сборка пакетов
QByteArray PacketManager::buildPack(quint8 id, quint8 length, QByteArray data)
{
    QByteArray completePack;
    QDataStream putInfo(&completePack, QIODevice::WriteOnly);
    putInfo << id;
    putInfo << length;
    for (int i = 0; i < data.size(); ++i) {
        putInfo << data[i];
    }
    putInfo.device()->close();
    return completePack;
}

QByteArray PacketManager::buildPack(quint8 id) //Deal
{
    QByteArray completePack;
    quint8 length = 1;
    quint8 data = 0;
    QDataStream putInfo(&completePack, QIODevice::WriteOnly);
    putInfo << id;
    putInfo << length;
    putInfo << data;
    putInfo.device()->close();
    return completePack;
}
