#ifndef DRAGTABLEWIDGET_H
#define DRAGTABLEWIDGET_H
#include <QTableWidget>
#include <QWidget>

class DragTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    DragTableWidget(QWidget *parent);
    void setTableDataFromQString(QString url);
    QString tableFileUrl;
    QString getTableFileUrl();
    void setTableFileUrl(const QString &value);
    bool hasData = false;

signals:
    void tableChangeSignal(bool b);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // DRAGTABLEWIDGET_H
