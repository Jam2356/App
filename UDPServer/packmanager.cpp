#include "packmanager.h"

PackManager::PackManager(QObject *parent)
    : QObject{parent}
{

}

//Работа с полученными пакетами
quint8 PackManager::takeID(QByteArray datagram)
{
    for (int i = 0; i < packets.size(); i++) {
        if(datagram[0] == packets[i]) {
            return id = packets[i];
        }
    }
    return 100;
}

quint8 PackManager::takeLength(QByteArray datagram)
{
    return length = datagram[1];
}

QByteArray PackManager::takeReleaseData(QByteArray receivDatagram)
{
    QByteArray releaseDatagram;
    int s = receivDatagram.size() - 2;
    releaseDatagram = receivDatagram.mid(2, s);
    return releaseDatagram;
}

//Сборка пакетов
QByteArray PackManager::buildPack(quint8 id, quint8 length, QByteArray data) //Собирает норм, на стороне клиента норм разбирает, осталось обменяться
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

QByteArray PackManager::buildPack(quint8 id)
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
