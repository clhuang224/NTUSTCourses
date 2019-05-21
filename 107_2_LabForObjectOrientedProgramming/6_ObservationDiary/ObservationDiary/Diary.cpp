#include "Diary.h"

vector<Page> Diary::diary;

// Intent: 開始新的一頁紀錄
// Pre: 日期字串
// Post: 頁數增加
void Diary::NewDay(string newDate)
{
    Diary::diary.push_back(Page(newDate));
}

// Intent: 取得最新一頁的index
// Pre: 無
// Post: 回傳index
unsigned Diary::getTodayIndex()
{
    return Diary::diary.size() - 1;
}

// Intent: 寫紀錄
// Pre: 生物名稱、部位名稱、前後數值
// Post: 指定最新的一頁Page寫紀錄
void Diary::writeDiary(string creature,string part,unsigned before,unsigned after)
{
    Diary::diary[Diary::diary.size() - 1].writeLog(creature,part,before,after);
}

// Intent: 印出特定生物的紀錄
// Pre: 生物名稱、生日index
// Post: 印出該生物出生以後所有的紀錄
void Diary::printDiary(string creature, unsigned birthdayIndex)
{
    
    for (unsigned i=0;i<diary.size();i++)
    {
        if (i >= birthdayIndex)
        {
            cout << "Day " << diary[i].getDate() << endl;
            for (unsigned j = 0; j < diary[i].Size(); j++)
            {
                Log temp = diary[i].getLog(j);
                if (temp.getCreature() == creature)
                {
                    cout << temp.getCreature() << "'s " << temp.getPart();
                    if (temp.getBefore() == 0 && temp.getAfter() > 0)
                    {
                        cout << " appeared";
                    }
                    else if (temp.getBefore() != 0 && temp.getBefore() < temp.getAfter())
                    {
                        cout << " increased";
                    }
                    else if (temp.getBefore() > temp.getAfter() && temp.getAfter() != 0)
                    {
                        cout << " decreased";
                    }
                    else if (temp.getBefore() > 0 && temp.getAfter() == 0)
                    {
                        cout << " disappeared";
                    }
                    cout << " (" << temp.getBefore() << " -> " << temp.getAfter() << ")." << endl;
                }
            }
        }
            

    }
}