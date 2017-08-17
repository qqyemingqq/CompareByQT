#ifndef DRAGTABLEWIDGET_H
#define DRAGTABLEWIDGET_H
#include <QTableWidget>
#include <QWidget>

class DragTableWidget : public QTableWidget
{
public:
    DragTableWidget(QWidget *parent);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
};

#endif // DRAGTABLEWIDGET_H
