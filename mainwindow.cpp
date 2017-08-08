#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "compareoperate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidget *t = new QTableWidget();
    QString *str = new QString("123");
    ComepareOperate *co = new ComepareOperate();
    co->PlaceTableDate(t,str);
}

MainWindow::~MainWindow()
{
    delete ui;
}
