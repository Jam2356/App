#include "initmodule.h"
#include <QApplication>
//v1_1_2 Client
//Изменения: проект полностью переработан и приведен к модульному виду,
//           добавлена проверка на пустую строку перед отправкой в widget.cpp,
//           добавлена возможность работать с русским языком
//TO DO: добавить возможность unbind/rebind
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule init;
    init.initialization();
    init.objInterface->show();

    return a.exec();
}
