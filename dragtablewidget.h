#ifndef DRAGTABLEWIDGET_H
#define DRAGTABLEWIDGET_H
#include <QTableWidget>
#include <QWidget>
#include "compareoperate.h"
class DragTableWidget : public QTableWidget
{
public:
    DragTableWidget(QWidget *parent);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
private:
    CompareOperate *co = new CompareOperate();
};

#endif // DRAGTABLEWIDGET_H
