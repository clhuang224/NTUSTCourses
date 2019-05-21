#include <iostream>
#include <string>
#include "Diary.h"
using namespace std;

class Part
{
public:
    Part(string, string, unsigned = 0);     // 初始化
    string getName();                       // 取得部位名稱
    unsigned getAmount();                   // 取得部位數量
    void operator=(unsigned);               // 定義Part物件的=
    void operator+=(int);                   // 定義Part物件的+=
    void operator-=(int);                   // 定義Part物件的-=
private:
    string creature;
    string name;
    unsigned amount;
};