#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include "dragtablewidget.h"
#include <vector>

using namespace std;

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

    void beginCompareTables();

private:
    Ui::MainWindow *ui;
    void beginCompare(DragTableWidget *table,QString path);
    void installSignal();
    void placeTableDate(QTableWidget* tableWidget, QString fileUrl);

    vector<int> sameRows;
    vector<int> uniqueValueInVector(vector<int> v);

    QScrollBar* verticalScrollBarLeft;
    QScrollBar* horizontalScrollBarLeft;
    QScrollBar* verticalScrollBarRight;
    QScrollBar* horizontalScrollBarRight;
    bool hasDifferent;
};

#endif // MAINWINDOW_H
