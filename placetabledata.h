#ifndef COMEPAREOPERATE_H
#define COMEPAREOPERATE_H

#include <QWidget>
#include <QTableWidget>

class PlaceTableData
{

public:
    PlaceTableData();
    void PlaceTableDate(QTableWidget *tableWidget, QString fileUrl);
    const char* qStringToCppStr(QString qstr);
};

#endif // COMEPAREOPERATE_H
