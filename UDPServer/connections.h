#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <QObject>
#include <QVector>
#include "buffers.h"

class Connections : public QObject
{
    Q_OBJECT
public:
    explicit Connections(QObject *parent = nullptr);
    bool addConnection();
    bool delConnection();

private:
    QVector<Buffers> connections_buffers;


signals:

};

#endif // CONNECTIONS_H
