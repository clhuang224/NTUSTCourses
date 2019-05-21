#include "File.h"


// Intent: 初始化
// Pre: 0~2個字串
// Post: 初始化完成
File::File(string newText, string newPathname) :Document(newText)
{
    pathname = newPathname;
}

// Intent: 取得pathname
// Pre: File物件
// Post: 回傳字串
string File::getPathname()
{
    return pathname;
}

// Intent: 設定pathname
// Pre: File物件
// Post: pathname被改變
void File::setPathname(string newPathname)
{
    pathname = newPathname;
}

// Intent: 定義File的assign
// Pre: 兩個File物件
// Post: 回傳this
File& File::operator =(File another)
{
    setText(another.getText());
    pathname = another.pathname;
    return *this;
}