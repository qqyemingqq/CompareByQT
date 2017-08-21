#ifndef DRAGTABLEWIDGET_H
#define DRAGTABLEWIDGET_H
#include <QTableWidget>
#include <QWidget>

class DragTableWidget : public QTableWidget
{
public:
    DragTableWidget(QWidget *parent);
    void setTableDataFromQString(QString url);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // DRAGTABLEWIDGET_H
