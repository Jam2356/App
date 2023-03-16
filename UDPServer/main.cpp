//#include "widget.h"
#include "initmodule.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initModule in;
    in.initInterface();

//    Widget w;
//    w.show();
    return a.exec();
}
