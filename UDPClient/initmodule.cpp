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

    connect(objConnection, SIGNAL(connectSetBlock()),
            objInterface, SLOT(connectUnavailable()));

    connect(objInterface, SIGNAL(connectClicked(QHostAddress,quint16)),
            objConnection, SLOT(connectWait(QHostAddress,quint16)));

    connect(objInterface, SIGNAL(sendClicked(QString)),
            objConnection, SLOT(sendWait(QString)));

    connect(objInterface, SIGNAL(closeWidgetClicked()),
            objConnection, SLOT(disconnectWait()));

}
