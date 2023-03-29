#ifndef BUFFERS_H
#define BUFFERS_H

#include <QObject>

class Buffers : public QObject
{
    Q_OBJECT
public:
    explicit Buffers(QObject *parent = nullptr);
    bool addConnection();
    bool delConnection();

    bool bushBackIn(QByteArray socketToBuffer);
    bool bushBackCore(QByteArray coreToBuffer);
    bool readToCore(QByteArray bufferToCore);
    bool readOut(QByteArray bufferToCore);

private:
    QByteArray in[64];
    QByteArray out[64];


signals:

};

//Такое исполнение не хочет, попробуем сделать внутри этого класса или внутри класса сервер
//QVector<Buffers> connections_buffers;


#endif // BUFFERS_H
