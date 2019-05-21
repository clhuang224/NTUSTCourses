#ifndef EMAIL_H
#define EMAIL_H

#include "Document.h"
class Email :
    public Document
{
private:
    string sender;
    string recipient;
    string title;
public:
    Email(string="", string = "", string = "", string = "");

    string getSender();
    string getRecipient();
    string getTitle();

    void getSender(string);
    void getRecipient(string);
    void getTitle(string);

    Email& operator =(Email);
};


#endif // !EMAIL_H


