#include "Part.h"
using namespace std;

class Creature
{
public:
    Creature(string);               // 初始化
    Creature(string, Creature);     // 以另一個Creature的parts初始化
    string getName();               // 取得生物名稱
    vector<Part> getParts();        // 取得部位陣列
    Part& operator[](string);       // 定義Creature物件的[]
    void PrintStatus();             // 印出生物當下狀況
    void PrintLog();                // 印出該生物的紀錄
private:
    string name;
    unsigned birthdayIndex;
    vector<Part> parts;
};