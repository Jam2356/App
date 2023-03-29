#include "initmodule.h"
#include <QApplication>
//v1_1_4 Client
//Изменения: Добавлена отправка на сервер хендшейк-сообщения
//TO DO: Может быть стоит удалить кнопку receive или убрать выбор порта сервера
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule init;
    init.initialization();
    init.objInterface->show();

    return a.exec();
}
