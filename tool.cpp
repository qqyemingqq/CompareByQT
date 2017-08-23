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
