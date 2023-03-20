#include "initmodule.h"
#include <QApplication>
//v1_1_1
//Изменения: добавлена функция и кнопка End receive (закрывает сокет), добавлена функция отправки сообщений кнопкой Send
//TO DO: Добавить проверку на пустую строку перед отправкой в widget.cpp
//TO DO: переделать Client
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule in;
    in.initialization();
    in.objInterface->show();

    return a.exec();
}

