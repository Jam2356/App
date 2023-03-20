#include "initmodule.h"

initModule::initModule(QObject *parent)
    : QObject{parent}
{
    objServer = new Server;
    objInterface = new Widget;

}

void initModule::initialization()
{
    connect(objServer, SIGNAL(datagramToInterface(QString)),
            objInterface, SLOT(datagramToDisplay(QString)));

    connect(objInterface, SIGNAL(endReceiveClicked()),
            objServer, SLOT(endReceiveWait()));

    connect(objInterface, SIGNAL(sendClicked(QString,QHostAddress,quint16)),
            objServer, SLOT(sendWait(QString,QHostAddress,quint16)));

    connect(objInterface, SIGNAL(receiveClicked(QHostAddress,quint16)),
            objServer, SLOT(receiveWait(QHostAddress,quint16)));
}
