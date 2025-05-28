#include "Creature.h"

// Intent: 初始化
// Pre: 宣告Creature物件、生物名稱參數
// Post: name初始為參數、parts為空陣列、birthdayIndex為最新一頁紀錄的index
Creature::Creature(string newName)
{
    name = newName;
    parts = {};
    birthdayIndex = Diary::getTodayIndex();
}

// Intent: 以另一個Creature的parts初始化
// Pre: 宣告Creature物件、生物名稱參數、Creature參數
// Post: name初始為newName、parts為另一個Creature的parts、birthdayIndex為最新一頁紀錄的index
Creature::Creature(string newName, Creature another)
{
    name = newName;
    for (unsigned i = 0; i < another.parts.size(); i++)
    {
        parts.push_back(Part(name, another.parts[i].getName(), another.parts[i].getAmount()));
    }
    birthdayIndex = Diary::getTodayIndex();
}

// Intent: 取得生物名稱
// Pre: Creature物件
// Post: 回傳name
string Creature::getName()
{
    return name;
}

// Intent: 取得parts
// Pre: Part物件
// Post: 回傳parts
vector<Part> Creature::getParts()
{
    return parts;
}

// Intent: 定義Creature物件的[]
// Pre: Creature物件、部位名稱參數
// Post: 若該部位存在於陣列中，回傳該Part；若不存在則新增在陣列尾端，並回傳該Part
Part& Creature::operator[](string part)
{
    if (parts.empty())
    {
        parts.push_back(Part(name, part));
        return parts[parts.size() - 1];
    }

    unsigned i = 0;
    while (i < parts.size() && parts[i].getName() != part)
    {
        i++;
    }
    if (i < parts.size() && parts[i].getName() == part)
    {
        return parts[i];
    }
    i = 0;
    while (i < parts.size() && parts[i].getName() < part)
    {
        i++;
    }
    if (i < parts.size())
    {
        parts.insert(parts.begin() + i, Part(name, part));
    }
    else
    {
        parts.push_back(Part(name, part));
    }
    return parts[i];
}

// Intent: 印出生物當下狀況
// Pre: Creature物件
// Post: 印出結果
void Creature::PrintStatus()
{
    cout << name << "'s status:" << endl;
    for (unsigned i = 0; i < parts.size(); i++)
    {
        if (parts[i].getAmount() > 0)
        {
            cout << parts[i].getName() << " * " << parts[i].getAmount() << endl;
        }
    }
    cout << endl;
}

// Intent: 印出該生物的紀錄
// Pre: Creature物件
// Post: 印出結果
void Creature::PrintLog()
{
    cout << name << "'s log:" << endl;
    Diary::printDiary(name, birthdayIndex);
    cout << endl;
}