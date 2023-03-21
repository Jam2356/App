#ifndef INITMODULE_H
#define INITMODULE_H

#include <QObject>
#include <QDebug>

#include "server.h"
#include "widget.h"

class initModule : public QObject
{
    Q_OBJECT
public:
    explicit initModule(QObject *parent = nullptr);
    void initialization();

    Server *objServer;
    Widget *objInterface;

private:
    Widget w;

signals:

};

#endif // INITMODULE_H
