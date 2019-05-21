#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
using namespace std;
class Document
{
public:
    Document(string = "");
private:
    string text;
public:
    string getText();
    void setText(string);
    Document& operator =(Document);
};

#endif // !DOCUMENT_H

