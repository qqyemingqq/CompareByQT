#include "dragTablewidget.h"
#include "qdebug.h"
#include "tool.h"
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include "xlsxdocument.h"

DragTableWidget::DragTableWidget(QWidget* parent)
    :QTableWidget(parent)
{
    setAcceptDrops(true);
}

void DragTableWidget::setTableDataFromQString(QString url)
{
    QXlsx::Document xlsx(Tool::getInstance()->qStringToCppStr(url));
    qDebug()<<xlsx.read("A1");
    int cols = this->columnCount();
    int rows = this->rowCount();
    qDebug()<<Tool::getInstance()->qStringToCppStr(url)<<rows<<cols<<endl;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            this->setItem(r,c,new QTableWidgetItem(xlsx.read(r+1,c+1).toString()));
        }
    }
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
            setTableDataFromQString(url.url(QUrl::PreferLocalFile));
        }
    }
}

