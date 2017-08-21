#include "compareoperate.h"
#include "qdebug.h"
#include "xlsxdocument.h"


CompareOperate::CompareOperate()
{
}

void CompareOperate::PlaceTableDate(QTableWidget* tableWidget, QString fileUrl)
{

    QXlsx::Document xlsx(CompareOperate::qStringToCppStr(fileUrl));
    qDebug()<<xlsx.read("A1");
    int cols = tableWidget->columnCount();
    int rows = tableWidget->rowCount();
    qDebug()<<CompareOperate::qStringToCppStr(fileUrl)<<rows<<cols<<endl;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            tableWidget->setItem(r,c,new QTableWidgetItem(xlsx.read(r+1,c+1).toString()));
//            qDebug()<<tableWidget->item(c,r)<<endl;
        }
    }
}
const char* CompareOperate::qStringToCppStr(QString qstr)
{
    std::string str = qstr.toStdString();
    const char* url = str.c_str();
    return url;
}