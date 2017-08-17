#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include "dragtablewidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_selectFileLeft_clicked();

    void on_selectFileRight_clicked();

    void on_fileUrlRight_returnPressed();

    void on_fileUrlLeft_returnPressed();

    void slotTest(int d);

private:
    Ui::MainWindow *ui;
    bool loadSuccessLeft = false;
    bool loadSuccessRight = false;

    void beginCompare();
    void syncTablePosition();
//    void dragMoveEvent(QDragMoveEvent *event);

    QScrollBar* verticalScrollBarLeft;
    QScrollBar* horizontalScrollBarLeft;
    QScrollBar* verticalScrollBarRight;
    QScrollBar* horizontalScrollBarRight;
};

#endif // MAINWINDOW_H
