#include "Page.h"

// Intent: 初始化
// Pre: 宣告Page物件、日期字串參數
// Post: date初始化為參數、logs為空陣列
Page::Page(string newDate)
{
    date = newDate;
    logs = {};
}

// Intent: 取得Page日期
// Pre: Page物件
// Post: 回傳date
string Page::getDate()
{
    return date;
}

// Intent: 取得特定紀錄
// Pre: index
// Post: 回傳特定Log物件
Log Page::getLog(unsigned index)
{
    return logs[index];
}

// Intent: 取得logs陣列的大小
// Pre: Page物件
// Post: 回傳陣列大小
unsigned Page::Size()
{
    return logs.size();
}

// Intent: 寫紀錄
// Pre: 生物名稱、部位名稱、前後數值
// Post: 將紀錄參數存進logs陣列
void Page::writeLog(string creature, string part, unsigned before, unsigned after)
{
    logs.push_back(Log(creature, part, before, after));
}
