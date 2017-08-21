#ifndef TOOL_H
#define TOOL_H
#include <QWidget>

class Tool
{
public:
    const char* qStringToCppStr(QString qstr);
    static Tool* getInstance();
    beginCompareTables(QTableWidget *leftTable, QTableWidget *rightTable);
private:
    Tool();
    Tool(const Tool&);
    Tool& operator=(const Tool&);
    static Tool* instance;
};

#endif // TOOL_H
