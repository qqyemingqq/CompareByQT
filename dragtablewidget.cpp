#include "dragTablewidget.h"
#include "qdebug.h"

#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QMimeData>

DragTableWidget::DragTableWidget(QWidget* parent)
    :QTableWidget(parent)
{
    setAcceptDrops(true);
}

void DragTableWidget::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void DragTableWidget::dragMoveEvent(QDragMoveEvent *event)
{
//    event->acceptProposedAction();
}
void DragTableWidget::dropEvent(QDropEvent *event)
{
    const QMimeData* md =event->mimeData();
    qDebug()<<"droped"<<md->hasUrls();
    if(md->hasUrls())
    {
        foreach (QUrl url,md->urls()) {
            qDebug()<< url.url(QUrl::PreferLocalFile);
            co->PlaceTableDate(this,url.url(QUrl::PreferLocalFile));
        }
    }
}
