#include "initmodule.h"

initModule::initModule(QObject *parent)
    : QObject{parent}
{
//    Widget w;
}

bool initModule::initInterface()
{
    w.show();
    qDebug() << "Nice showed";
}
bool initModule::initServer()
{
    // как то толкнуть сюда ui чтоб сервер заработал
}
