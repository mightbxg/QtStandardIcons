#include "widget.h"

#include <QApplication>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "note: use -style to set icon style." << std::endl;

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
