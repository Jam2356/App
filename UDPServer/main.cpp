#include "initmodule.h"
#include <QApplication>
//v1_1_3 Server
//Изменения: Обновлена система получения и использования порта клиента
//           На клиенте проведены встречные мероприятия
//           Исправлена ошибка из за которой команда endReceive не позволяла возобновить "соединени"
//TO DO: организовать мультипоточность
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule init;
    init.initialization();
    init.objInterface->show();

    return a.exec();
}

