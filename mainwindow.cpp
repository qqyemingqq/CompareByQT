#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "compareoperate.h"
#include <ActiveQt/QAxObject>
#include <QtSql/QSqlDatabase>
#include "qdebug.h"
#include <QFileDialog>
#include <QMessageBox>


ComepareOperate *co = new ComepareOperate();


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidget *t = new QTableWidget();
    QString *str = new QString("Excel.Application");
//    char *file = "C:/Users/Ye/CompareByQT/res/ex.xlsx";
    // char *file = "D:/SVN_new/策划/2.数据配置表/测试用表/兵种/soldier.xlsx";

//    co->PlaceTableDate(ui->tableRight,str);9
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectFileLeft_clicked()
{
    qDebug()<<"clicked on_selectFileLeft_clicked";
    QString path = QFileDialog::getOpenFileName(this, tr("Open Xlsx"), ".", tr("Image Files(*.xlsx)"));
    if(path.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        ui->fileUrlLeft->setText(path);
        co->PlaceTableDate(ui->tableLeft,path);
        loadSuccessLeft = true;
    }
    beginCompare();
}

void MainWindow::on_selectFileRight_clicked()
{
    qDebug()<<"clicked on_selectFileRight_clicked";
    QString path = QFileDialog::getOpenFileName(this, tr("Open Xlsx"), ".", tr("Image Files(*.xlsx)"));
    if(path.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        ui->fileUrlRight->setText(path);
        co->PlaceTableDate(ui->tableRight,path);
        loadSuccessRight = true;
    }
    beginCompare();
}

void MainWindow::beginCompare()
{
    if(loadSuccessLeft&&loadSuccessRight)
    {
        qDebug()<<"successed";
        //TODO
        auto rowsL = ui->tableLeft->rowCount();
        auto colsL = ui->tableLeft->columnCount();
        auto rowsR = ui->tableRight->rowCount();
        auto colsR = ui->tableRight->columnCount();
        auto minCol = colsL<=colsR?colsL:colsR;
        auto minRow = rowsL<=rowsR?rowsL:rowsR;
        for(int c=0;c<minCol;c++)
        {
            for(int r=0;r<minRow;r++)
            {
                qDebug()<<ui->tableLeft->item(r,c)->text();
                if(ui->tableLeft->item(r,c)->text()!=ui->tableRight->item(r,c)->text())
                {
                    ui->tableLeft->item(r,c)->setBackgroundColor(QColor(255,0,0));
                    ui->tableRight->item(r,c)->setBackgroundColor(QColor(255,0,0));
                }
            }
        }

    }
}

void MainWindow::on_fileUrlRight_returnPressed()
{
    auto path = ui->fileUrlRight->text();
    ui->fileUrlRight->setText(path);
    co->PlaceTableDate(ui->tableRight,path);
    loadSuccessRight = true;
    beginCompare();
}

void MainWindow::on_fileUrlLeft_returnPressed()
{
    auto path = ui->fileUrlRight->text();
    ui->fileUrlLeft->setText(path);
    co->PlaceTableDate(ui->tableLeft,path);
    loadSuccessLeft = true;
    beginCompare();
}
