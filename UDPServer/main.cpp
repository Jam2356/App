#include "initmodule.h"
#include <QApplication>
//v1_1_5 Server
//Изменения: Прием хендшейк сообщения, а так же проверка на подключенных пользователей
// Убраны кнопки receive и end connect, установлен порт 100
//TO DO: Работы много SQL, организация потоков и работы буферов и мб что то с регистрацией, логика сверху еще
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule init;
    init.initialization();
    init.objInterface->show();

    return a.exec();
}

