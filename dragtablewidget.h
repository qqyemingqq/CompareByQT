#ifndef DRAGTABLEWIDGET_H
#define DRAGTABLEWIDGET_H
#include <QTableWidget>
#include <QWidget>
#include "placetabledata.h"

class DragTableWidget : public QTableWidget
{
public:
    DragTableWidget(QWidget *parent);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
private:
    PlaceTableData *co = new PlaceTableData();
};

#endif // DRAGTABLEWIDGET_H
