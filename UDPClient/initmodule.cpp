#include "initmodule.h"

initModule::initModule(QObject *parent)
    : QObject{parent}
{
    objConnection = new Connection;
    objInterface = new Widget;
}

void initModule::initialization()
{
    connect(objConnection, SIGNAL(datagramToInterface(QString)),
            objInterface, SLOT(datagramToDisplay(QString)));

    connect(objInterface, SIGNAL(receiveClicked(QHostAddress)),
            objConnection, SLOT(receiveWait(QHostAddress)));

    connect(objInterface, SIGNAL(sendClicked(QString,QHostAddress,quint16)),
            objConnection, SLOT(sendWait(QString,QHostAddress,quint16)));
}
