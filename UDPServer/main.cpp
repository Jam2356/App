#include "initmodule.h"
#include <QApplication>
//v1_1_6 Server
//Изменения: Отредактирован код, настроена работа пакетов 0,1,2,3,5, настроена работа меню вывода
//TO DO: ...
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule init;
    init.initialization();
    init.objInterface->show();

    return a.exec();
}

