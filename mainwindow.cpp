#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "compareoperate.h"
#include <ActiveQt/QAxObject>
#include <QtSql/QSqlDatabase>
#include "xlsxdocument.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidget *t = new QTableWidget();
    QString *str = new QString("Excel.Application");
    ComepareOperate *co = new ComepareOperate();
    co->PlaceTableDate(ui->tableLeft,str);
    co->PlaceTableDate(ui->tableRight,str);
    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello Qt!");
    xlsx.saveAs("Test.xlsx");
}

MainWindow::~MainWindow()
{
    delete ui;
}
