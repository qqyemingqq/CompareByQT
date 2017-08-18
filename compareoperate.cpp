#include "compareoperate.h"
#include "qdebug.h"
#include "xlsxdocument.h"


ComepareOperate::ComepareOperate()
{
//    auto excel = new QAxObject("Excel.Application");
}

void ComepareOperate::PlaceTableDate(QTableWidget* &tableWidget, QString fileUrl)
{
    std::string url_ba = fileUrl.toStdString();
//    QByteArray url_ba = fileUrl.toLoacl8Bit();
    const char* url_c = url_ba.c_str();
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
