#include <QtWidgets>
#include <QTableWidgetItem>

#include "compare.h"


QTextStream cout(stdout, QIODevice::WriteOnly);
Compare::Compare(int rows, int cols, QWidget *parent)
    : QMainWindow(parent)
{
    QTableWidget createTable(rows,cols,parent);
    createTable.setParent(parent);
    cout<<"123"<<endl;

//  QTableWidget createTable2(9,9);
//  creteTable2->moveTo()
}

QTableWidget *createTable(int rows,int cols,QWidget *parent)
{
    auto *table = new QTableWidget(rows, cols,parent);
//    table->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    table->resize(800,500);
    for (int c = 0; c < cols; ++c) {
            QString character(QChar('A' + c));
            table->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
        }
    table->setItemPrototype(table->item(rows - 1, cols - 1));
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
    return table;
}
