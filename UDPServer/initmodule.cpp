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

    connect(objInterface, SIGNAL(sendClicked(QString,QHostAddress)),
            objServer, SLOT(sendWait(QString,QHostAddress)));
}
