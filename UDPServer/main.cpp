#include "initmodule.h"
#include <QApplication>
//v1_1
//Работает бинд, прием сообщений и вывод оных в поле chat

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule in;
    in.initialization();
    in.objInterface->show();

    return a.exec();
}

