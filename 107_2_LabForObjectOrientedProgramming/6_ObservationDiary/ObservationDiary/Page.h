#include "Log.h"
using namespace std;
class Page
{
public:
    Page(string);                                       // 初始化
    string getDate();                                   // 取得Page日期
    Log getLog(unsigned);                               // 取得特定紀錄
    unsigned Size();                                    // 取得logs陣列的大小
    void writeLog(string, string, unsigned, unsigned);  // 寫紀錄
private:
    string date;
    vector<Log> logs;
};