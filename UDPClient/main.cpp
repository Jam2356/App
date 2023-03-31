#include "initmodule.h"
#include <QApplication>
//v1_1_5 Client
//Изменения: Изменено хендшейк-сообщение, отредактирована работа кнопки receive
//TO DO: Дальнейших изменений не запланировано
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule init;
    init.initialization();
    init.objInterface->show();

    return a.exec();
}
