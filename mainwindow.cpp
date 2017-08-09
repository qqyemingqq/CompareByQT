#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "compareoperate.h"
#include <ActiveQt/QAxObject>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidget *t = new QTableWidget();
    QString *str = new QString("123");
    ComepareOperate *co = new ComepareOperate();
    co->PlaceTableDate(ui->tableLeft,str);
    co->PlaceTableDate(ui->tableRight,str);
    auto excel = new QAxObject(("Excel.Application"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
