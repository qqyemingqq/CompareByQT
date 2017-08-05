#ifndef COMPARE_H
#define COMPARE_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableWidgetItem;
class QTableWidget;
QT_END_NAMESPACE

class Compare : public QMainWindow
{
    Q_OBJECT

public:

    Compare(int rows, int cols, QWidget *parent = 0);
private:
    QTableWidget *createTable(int rows,int cols);


};

#endif // COMPARE_H
