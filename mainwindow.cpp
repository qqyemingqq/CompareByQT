#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "placetabledata.h"
//#include <ActiveQt/QAxObject>
#include <QtSql/QSqlDatabase>
#include "qdebug.h"
#include <QFileDialog>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->verticalLayoutWidget);

    verticalScrollBarLeft = ui->tableLeft->verticalScrollBar();
    horizontalScrollBarLeft = ui->tableLeft->horizontalScrollBar();
    verticalScrollBarRight = ui->tableRight->verticalScrollBar();
    horizontalScrollBarRight = ui->tableRight->horizontalScrollBar();

    syncTablePosition();
    qDebug()<<ui->tableLeft;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectFileLeft_clicked()
{
    qDebug()<<"clicked on_selectFileLeft_clicked";
    QString path = QFileDialog::getOpenFileName(this, tr("Open Xlsx"), ".", tr("Excel Files(*.xlsx)"));
    if(path.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        ui->fileUrlLeft->setText(path);
        beginCompare(ui->tableLeft,path);
    }
}

void MainWindow::on_selectFileRight_clicked()
{
    qDebug()<<"clicked on_selectFileRight_clicked";
    QString path = QFileDialog::getOpenFileName(this, tr("Open Xlsx"), ".", tr("Image Files(*.xlsx)"));
    if(path.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        ui->fileUrlRight->setText(path);
        beginCompare(ui->tableRight,path);
    }
}

void MainWindow::beginCompare(QTableWidget* table, QString path)
{
    co->PlaceTableDate(table,path);
    compareTables.beginCompareTables(ui->tableLeft,ui->tableRight);
}

void MainWindow::on_fileUrlRight_returnPressed()
{
    auto path = ui->fileUrlRight->text();
    ui->fileUrlRight->setText(path);
    beginCompare(ui->tableRight,path);
}

void MainWindow::on_fileUrlLeft_returnPressed()
{
    auto path = ui->fileUrlRight->text();
    ui->fileUrlLeft->setText(path);
    beginCompare(ui->tableLeft,path);
}

void MainWindow::syncTablePosition()
{
    QObject::connect((QWidget*)verticalScrollBarLeft,SIGNAL(valueChanged(int)),verticalScrollBarRight,SLOT(setValue(int)));
    QObject::connect((QWidget*)horizontalScrollBarLeft,SIGNAL(valueChanged(int)),horizontalScrollBarRight,SLOT(setValue(int)));
    QObject::connect((QWidget*)verticalScrollBarRight,SIGNAL(valueChanged(int)),verticalScrollBarLeft,SLOT(setValue(int)));
    QObject::connect((QWidget*)horizontalScrollBarRight,SIGNAL(valueChanged(int)),horizontalScrollBarLeft,SLOT(setValue(int)));
}
void MainWindow::slotTest(int d)
{
    qDebug()<<d;
    qDebug()<<"runed";
}
