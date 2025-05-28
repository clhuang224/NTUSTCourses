#include "Email.h"

// Intent: 初始化
// Pre: 0~4個字串
// Post: 初始化完成
Email::Email(string newText, string newSender, string newRecipient, string newTitle) :Document(newText)
{
    sender = newSender;
    recipient = newRecipient;
    title = newTitle;
}

// Intent: 取得sender
// Pre: Email物件
// Post: 回傳字串
string Email::getSender()
{
    return sender;
}

// Intent: 取得recipient
// Pre: Email物件
// Post: 回傳字串
string Email::getRecipient()
{
    return recipient;
}

// Intent: 取得title
// Pre: Email物件
// Post: 回傳字串
string Email::getTitle()
{
    return title;
}

// Intent: 設定sender
// Pre: Email物件
// Post: sender被改變
void Email::getSender(string newSender)
{
    sender = newSender;
}

// Intent: 設定recipient
// Pre: Email物件
// Post: recipient被改變
void Email::getRecipient(string newRecipient)
{
    recipient = newRecipient;
}

// Intent: 設定title
// Pre: Email物件
// Post: title被改變
void Email::getTitle(string newTitle)
{
    title = newTitle;
}

// Intent: 定義Email的assign
// Pre: 兩個Email物件
// Post: 回傳this
Email& Email::operator =(Email another)
{
    setText(another.getText());
    sender = another.sender;
    recipient = another.recipient;
    title = another.title;
    return *this;
}