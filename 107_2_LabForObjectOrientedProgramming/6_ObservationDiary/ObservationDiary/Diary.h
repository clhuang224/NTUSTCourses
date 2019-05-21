#include <iostream>
#include <string>
#include <vector>
#include "Page.h"
using namespace std;
class Diary
{
public:
    static void NewDay(string);                                     // 開始新的一頁紀錄
    static unsigned getTodayIndex();                                // 取得最新一頁的index
    static void writeDiary(string, string, unsigned, unsigned);     // 寫紀錄
    static void printDiary(string, unsigned);                       // 印出特定生物出生以後所有的紀錄
private:
    static vector<Page> diary;                                      // 記錄所有生物的紀錄
};