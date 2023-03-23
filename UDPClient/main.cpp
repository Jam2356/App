#include "initmodule.h"
#include <QApplication>
//v1_1_3 Client
//Изменения: Обновлена система генерации порта, порт больше не связан с портом сервера
//           На сервере проведены встречные мероприятия
//TO DO: добавить возможность unbind/rebind
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule init;
    init.initialization();
    init.objInterface->show();

    return a.exec();
}
