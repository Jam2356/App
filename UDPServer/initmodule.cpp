#include "initmodule.h"

initModule::initModule(QObject *parent)
    : QObject{parent}
{
    objServer = new Server;
    objInterface = new Widget;

}

void initModule::initialization()
{
    connect(objInterface, SIGNAL(receiveClicked(QHostAddress,quint16)),
            objServer, SLOT(receiveWait(QHostAddress,quint16)));

    connect(objServer, SIGNAL(datagramToInterface(QString)),
            objInterface, SLOT(datagramToDisplay(QString)));
}
