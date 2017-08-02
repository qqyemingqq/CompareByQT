
#include <QApplication>
#include "compare.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    MainWindow w;
    Compare comp(6,6);

    comp.show();
//    w.show();

    return app.exec();
}
