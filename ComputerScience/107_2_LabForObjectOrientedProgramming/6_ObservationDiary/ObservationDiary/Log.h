#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Log
{
public:
    Log(string, string, unsigned, unsigned);    // 初始化
    string getCreature();                       // 取得生物名稱
    string getPart();                           // 取得部位名稱
    unsigned getBefore();                       // 取得改變前數值
    unsigned getAfter();                        // 取得改變後數值
private:
    string creature;
    string part;
    unsigned before;
    unsigned after;
};