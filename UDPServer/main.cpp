#include "initmodule.h"
#include <QApplication>
//v1_1_4 Server
//Изменения: Класс вектора connections
//TO DO: Сервер посылает хендшейк-сообщение, добавить прием и разбор этого сообщения
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule init;
    init.initialization();
    init.objInterface->show();

    return a.exec();
}

