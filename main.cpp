
#include <QApplication>
#include "compare.h"
#include "iostream"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    MainWindow w;
    Compare comp(6,6);
    comp.show();
    comp.resize(800,500);
//    w.show();

    return app.exec();
}
