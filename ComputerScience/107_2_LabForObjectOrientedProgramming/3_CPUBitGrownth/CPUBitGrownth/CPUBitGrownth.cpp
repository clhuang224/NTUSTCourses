#include <iostream>
#include <cmath>
using namespace std;
// Intent: 計算隨著年代的CPU可以計算階乘的上限
// Pre: 輸入年份
// Post: 輸出階乘參數
int main() {
    int y = 0;
    const int BASE_YEAR = 1900, BASE_K = 4, BASE_COUNTABLE = 15;
    while (y != EOF)
    {
        // 輸入年分
        cin >> y;
        double countable = BASE_K * pow(2, (y - BASE_YEAR) / 10);
        double nFac = 0;
        int n = 0;
        
        // 當階乘數小於上限時，繼續增加階乘（指數計算）
        while (nFac < countable)
        {
            n++;
            nFac += log10(n) / log10(2);
        }
        n--;

        // 輸出結果
        cout << n << endl;
    }
}
