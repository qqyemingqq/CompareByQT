#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    setCentralWidget(ui->verticalWidget);

    verticalScrollBarLeft = ui->tableLeft->verticalScrollBar();
    horizontalScrollBarLeft = ui->tableLeft->horizontalScrollBar();
    verticalScrollBarRight = ui->tableRight->verticalScrollBar();
    horizontalScrollBarRight = ui->tableRight->horizontalScrollBar();

    installSignal();

    hasDifferent = false;

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
        ui->tableLeft->setTableDataFromQString(path);
        beginCompareTables();
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
        beginCompareTables();
    }
}

void MainWindow::beginCompare(DragTableWidget* table, QString path)
{
    table->setTableDataFromQString(path);
    beginCompareTables();
}

void MainWindow::on_fileUrlRight_returnPressed()
{
    auto path = ui->fileUrlRight->text();
    ui->fileUrlRight->setText(path);
    beginCompareTables();
}

void MainWindow::on_fileUrlLeft_returnPressed()
{
    auto path = ui->fileUrlRight->text();
    ui->fileUrlLeft->setText(path);
    beginCompareTables();
}

void MainWindow::installSignal()
{
    QObject::connect(verticalScrollBarLeft,SIGNAL(valueChanged(int)),verticalScrollBarRight,SLOT(setValue(int)));
    QObject::connect(horizontalScrollBarLeft,SIGNAL(valueChanged(int)),horizontalScrollBarRight,SLOT(setValue(int)));
    QObject::connect(verticalScrollBarRight,SIGNAL(valueChanged(int)),verticalScrollBarLeft,SLOT(setValue(int)));
    QObject::connect(horizontalScrollBarRight,SIGNAL(valueChanged(int)),horizontalScrollBarLeft,SLOT(setValue(int)));

    QObject::connect(ui->tableLeft,SIGNAL(tableChangeSignal(bool)),this,SLOT(beginCompareTables()));
    QObject::connect(ui->tableRight,SIGNAL(tableChangeSignal(bool)),this,SLOT(beginCompareTables()));
}
void MainWindow::slotTest(int d)
{
    qDebug()<<d;
    qDebug()<<"runed";
}

void MainWindow::beginCompareTables()
{
    qDebug()<<"successed";
    auto rowsL = ui->tableLeft->rowCount();
    auto colsL = ui->tableLeft->columnCount();
    auto rowsR = ui->tableRight->rowCount();
    auto colsR = ui->tableRight->columnCount();
    auto minCol = colsL<=colsR?colsL:colsR;
    auto minRow = rowsL<=rowsR?rowsL:rowsR;

    vector<QTableWidgetItem*> tempBgList;
    vector<QTableWidgetItem*> tempFontList;


    for(int c=0;c<minCol;c++)
    {
        for(int r=0;r<minRow;r++)
        {
            if(ui->tableRight->hasData&&ui->tableLeft->hasData)
            {
                if(ui->tableLeft->item(r,c)->text()!=ui->tableRight->item(r,c)->text())
                {
                    hasDifferent = true;
                    ui->tableLeft->item(r,c)->setTextColor(QColor(255,0,0));
                    tempFontList.push_back(ui->tableLeft->item(r,c));
                    ui->tableRight->item(r,c)->setTextColor(QColor(255,0,0));
                    tempFontList.push_back(ui->tableRight->item(r,c));
                    sameRows.push_back(r);
                    if(r == minRow)
                    {
                        for(int c1=0;c1<ui->tableLeft->columnCount();c1++)
                        {
                            ui->tableLeft->item(r,c1)->setBackgroundColor(QColor(33,33,33,100));
                            tempBgList.push_back(ui->tableLeft->item(r,c1));
                            ui->tableRight->item(r,c1)->setBackgroundColor(QColor(33,33,33,100));
                            tempBgList.push_back(ui->tableRight->item(r,c1));
                        }
                    }
                }
            }
        }
    }
    qDebug()<<"reset:"<<(!hasDifferent && ui->tableLeft->hasData && ui->tableRight->hasData);
    if(hasDifferent && ui->tableLeft->hasData && ui->tableRight->hasData)
    {
        for(size_t i=0;i<tempBgList.size();i++)
        {
            tempBgList[i]->setBackgroundColor(QColor(0,0,0,0));
        }
//        for(int i=0;tempFontList.size();i++)
//        {
//            tempFontList[i]->setTextColor(QColor(0,0,0));
//        }
    }
}

vector<int> MainWindow::uniqueValueInVector(vector<int> v){
    vector<int>::iterator vector_iterator;
    sort(v.begin(),v.end());
    vector_iterator = unique(v.begin(),v.end());
    if(vector_iterator != v.end()){
        v.erase(vector_iterator,v.end());
    }
    return v;
}
