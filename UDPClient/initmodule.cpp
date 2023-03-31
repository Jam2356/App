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

    connect(objConnection, SIGNAL(receiveSetBlock()),
            objInterface, SLOT(receiveUnavailable()));

    connect(objInterface, SIGNAL(receiveClicked(QHostAddress,quint16)),
            objConnection, SLOT(receiveWait(QHostAddress,quint16)));

    connect(objInterface, SIGNAL(sendClicked(QString,QHostAddress,quint16)),
            objConnection, SLOT(sendWait(QString,QHostAddress,quint16)));

}
