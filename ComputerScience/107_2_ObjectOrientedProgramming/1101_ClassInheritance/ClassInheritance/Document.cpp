#include "Document.h"

// Intent: 初始化
// Pre: 0~1個字串
// Post: 初始化完成
Document::Document(string newText)
{
    text = newText;
}

// Intent: 取得text
// Pre: Document物件
// Post: 回傳字串
string Document::getText()
{
    return text;
}

// Intent: 設定text
// Pre: Document物件
// Post: text被改變
void Document::setText(string newText)
{
    text = newText;
}

// Intent: 定義Document的assign
// Pre: 兩個Document物件
// Post: 回傳this
Document& Document::operator =(Document another)
{
    text = another.text;
    return *this;
}