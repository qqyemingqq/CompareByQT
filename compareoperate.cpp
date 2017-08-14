#include "compareoperate.h"
//#include <QTableWidget>
#include "qdebug.h"

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

void ComepareOperate::PlaceTableDate(QTableWidget* &tableWidget, QString fileUrl)
{
    QByteArray url_ba = fileUrl.toLatin1();
    char* url_c = url_ba.data();
    QXlsx::Document xlsx(url_c);
    qDebug()<<xlsx.read("A1");
    int cols = tableWidget->columnCount();
    int rows = tableWidget->rowCount();
    qDebug()<<url_c<<rows<<cols<<endl;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            tableWidget->setItem(r,c,new QTableWidgetItem(xlsx.read(r+1,c+1).toString()));
//            qDebug()<<tableWidget->item(c,r)<<endl;
        }
    }

}
