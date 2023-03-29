#include "buffers.h"

Buffers::Buffers(QObject *parent)
    : QObject{parent}
{

}

bool Buffers::addConnection()
{

    return 0;
}
bool Buffers::delConnection()
{
    return 0;
}

bool Buffers::bushBackIn(QByteArray socketToBuffer)
{
    return 0;
}
bool Buffers::bushBackCore(QByteArray coreToBuffer)
{
    return 0;
}
bool Buffers::readToCore(QByteArray bufferToCore)
{
    return 0;
}
bool Buffers::readOut(QByteArray bufferToCore)
{
    return 0;
}
