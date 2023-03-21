#ifndef INITMODULE_H
#define INITMODULE_H

#include <QObject>
#include <QDebug>

#include "connection.h"
#include "widget.h"

class initModule : public QObject
{
    Q_OBJECT
public:
    explicit initModule(QObject *parent = nullptr);
    void initialization();

    Widget *objInterface;
    Connection *objConnection;

private:
    Widget w;

signals:

};

#endif // INITMODULE_H
