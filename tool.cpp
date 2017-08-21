#include "tool.h"

Tool::Tool()
{

}

Tool* Tool::instance = new Tool();
Tool* Tool::getInstance(){
    return instance;
}

Tool::Tool(const Tool &)
{

}

Tool &Tool::operator=(const Tool &)
{

}
const char* Tool::qStringToCppStr(QString qstr)
{
    std::string str = qstr.toStdString();
    const char* url = str.c_str();
    return url;
}

void Tool::beginCompareTables(QTableWidget *leftTable, QTableWidget *rightTable)
{
    qDebug()<<"successed";
    auto rowsL = leftTable->rowCount();
    auto colsL = leftTable->columnCount();
    auto rowsR = rightTable->rowCount();
    auto colsR = rightTable->columnCount();
    auto minCol = colsL<=colsR?colsL:colsR;
    auto minRow = rowsL<=rowsR?rowsL:rowsR;
    for(int c=0;c<minCol;c++)
    {
        for(int r=0;r<minRow;r++)
        {
            qDebug()<<leftTable->item(r,c)->text();
            if(leftTable->item(r,c)->text()!=rightTable->item(r,c)->text())
            {
                leftTable->item(r,c)->setTextColor(QColor(255,0,0));
                rightTable->item(r,c)->setTextColor(QColor(255,0,0));
                if(true)
                {
                    for(int c1=0;c1<leftTable->columnCount();c1++)
                    {
                        leftTable->item(r,c1)->setBackgroundColor(QColor(33,33,33,100));
                        rightTable->item(r,c1)->setBackgroundColor(QColor(33,33,33,100));
                    }
                }
            }
        }
    }
}


