#ifndef FILE_H
#define FILE_H

#include "Document.h"
class File :
    public Document
{
private:
    string pathname;
public:
    File(string = "", string = "");
    string getPathname();
    void setPathname(string);
    File& operator =(File);
};

#endif // !FILE_H


