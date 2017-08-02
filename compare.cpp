#include <QtWidgets>
#include <QTableWidgetItem>

#include "compare.h"

Compare::Compare(int rows, int cols, QWidget *parent)
    : QMainWindow(parent)
{
    auto table = new QTableWidget(rows, cols, this);
    table->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
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
}
