#ifndef INITMODULE_H
#define INITMODULE_H

#include <QObject>
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

class initModule : public QObject
{
    Q_OBJECT
public:
    explicit initModule(QObject *parent = nullptr);
    bool initInterface();
    bool initServer();

private:
    Widget w;

signals:

};

#endif // INITMODULE_H
