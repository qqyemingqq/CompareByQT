#include "dragablewidget.h"
#include "qdebug.h"
dragableWidget::dragableWidget(QWidget *parent) : QTableWidget(parent)
{
    setAcceptDrops(true);
}

void dragableWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"draged";
}

void dragableWidget::dropEvent(QDropEvent *event)
{
    qDebug()<<"droped";
}
