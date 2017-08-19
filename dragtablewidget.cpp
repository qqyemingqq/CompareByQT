#include "dragtablewidget.h"
#include "qdebug.h"

#include <QDragMoveEvent>
#include <QDragEnterEvent>

DragTableWidget::DragTableWidget(QWidget* parent)
    :QTableWidget(parent)
{
    setAcceptDrops(true);
}

void DragTableWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"Entered"<<this;
    event->acceptProposedAction();
}

void DragTableWidget::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<"draged"<<this;
    event->acceptProposedAction();
}
void DragTableWidget::dropEvent(QDropEvent *event)
{
    qDebug()<<"droped"<<this;
}
