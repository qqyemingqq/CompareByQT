#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "compareoperate.h"
#include <ActiveQt/QAxObject>
#include <QtSql/QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidget *t = new QTableWidget();
    QString *str = new QString("Excel.Application");
    ComepareOperate *co = new ComepareOperate();
//    char *file = "C:/Users/Ye/CompareByQT/res/ex.xlsx";
    char *file = "D:/SVN_new/策划/2.数据配置表/测试用表/兵种/soldier.xlsx";
    ui->fileUrlLeft->setText(file);
    co->PlaceTableDate(ui->tableLeft,file);
//    co->PlaceTableDate(ui->tableRight,str);9
}

MainWindow::~MainWindow()
{
    delete ui;
}
