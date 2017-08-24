#ifndef TOOL_H
#define TOOL_H
#include <QWidget>

class Tool
{
public:
    const char* qStringToStdStr(QString qstr);
    static Tool* getInstance();
private:
    Tool();
    Tool(const Tool&);
    Tool& operator=(const Tool&);
    static Tool* instance;
};

#endif // TOOL_H
