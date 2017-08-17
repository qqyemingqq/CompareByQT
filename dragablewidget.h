#ifndef DRAGABLEWIDGET_H
#define DRAGABLEWIDGET_H

#include <QTableWidget>
#include <QWidget>

class dragableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit dragableWidget(QWidget *parent = nullptr);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
signals:

public slots:
};

#endif // DRAGABLEWIDGET_H
