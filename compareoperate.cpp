#include "compareoperate.h"
//#include <QTableWidget>
#include "qdebug.h"
#include <QFileDialog>
//#include <QScopedPointer>
//#include <QList>
//#include <QVariant>
#include <ActiveQt/QAxObject>
//#include <QXlsx>QXlsx
#include "xlsxdocument.h"

ComepareOperate::ComepareOperate()
{
//    auto excel = new QAxObject("Excel.Application");
}

void ComepareOperate::PlaceTableDate(QTableWidget* &tableWidget, char* fileUrl)
{
    QXlsx::Document xlsx(fileUrl);
    qDebug()<<xlsx.read("A1");
    int cols = tableWidget->columnCount();
    int rows = tableWidget->rowCount();
    qDebug()<<*fileUrl<<rows<<cols<<endl;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            tableWidget->setItem(r,c,new QTableWidgetItem(xlsx.read(r+1,c+1).toString()));
//            qDebug()<<tableWidget->item(c,r)<<endl;
        }
    }

}
