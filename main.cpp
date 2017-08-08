#include "mainwindow.h"
#include <QApplication>
#include <QTableWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*auto *table = new QTableWidget(9, 9,&w);
//    table->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    table->resize(800,500);
    for (int c = 0; c < 9; ++c) {
            QString character(QChar('A' + c));
            table->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
        }
    table->setItemPrototype(table->item(9 - 1, 9 - 1));
    QColor titleBackground(Qt::lightGray);
    QFont titleFont = table->font();
    titleFont.setBold(true);
    QString *str = new QString("123");
    table->setItem(1, 0, new QTableWidgetItem(*str,0));
    table->setItem(2, 0, new QTableWidgetItem(*str,0));
    table->setItem(3, 0, new QTableWidgetItem(*str,0));
    table->setItem(4, 0, new QTableWidgetItem(*str,0));
    table->setItem(5, 0, new QTableWidgetItem(*str,0));
    table->setItem(6, 0, new QTableWidgetItem(*str,0));
    table->setItem(7, 0, new QTableWidgetItem(*str,0));
    table->setItem(8, 0, new QTableWidgetItem(*str,0));
    table->setItem(9, 0, new QTableWidgetItem(*str,0));
    table->move(200,200);*/
    w.show();

    return a.exec();
}
