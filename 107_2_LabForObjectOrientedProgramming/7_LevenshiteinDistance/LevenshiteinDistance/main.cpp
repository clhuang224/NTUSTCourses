#include <iostream>
#include <string>
#include <vector>
using namespace std;
unsigned levenshiteinDistance(string, string);
unsigned minimum(unsigned, unsigned, unsigned);
int main() {
    string str1, str2;
    while (!cin.eof())
    {
        // 輸入兩筆字串
        getline(cin, str1);
        getline(cin, str2);
        // 印出結果
        cout << levenshiteinDistance(str1, str2) << endl;
    }
}

// Intent: 計算兩個字串的Levenshitein Distance
// Pre: 兩個string
// Post: 回傳unsigned
unsigned levenshiteinDistance(string str1, string str2)
{
    vector<vector<unsigned>> distance(1 + str1.length(), vector<unsigned>(1 + str2.length(), 9));
    for (unsigned i = 0; i <= str1.length(); i++)
    {
        for (unsigned j = 0; j <= str2.length(); j++)
        {
            
            if (i == 0)
            {
                // 第一個字串為空字串時，distance為第二個字串的長度
                distance[i][j] = j;
            }
            else if (j == 0)
            {
                // 第二個字串為空字串時，distance為第一個字串的長度
                distance[i][j] = i;
            }
            else
            {
                // 字串長度為i和j時所算出的distance
                distance[i][j] =
                    // 是三種情況的distance中的最小值
                    minimum(
                        // 1. 扣掉最後一個字的兩個字串所算出的distance + 最後一個字的distance（相同為0；不同為1）
                        distance[i - 1][j - 1] + static_cast<unsigned>(str1[i - 1] != str2[j - 1]),
                        // 2. 扣掉最後一個字的第一個字串和第二個字串所算出的distance
                        distance[i][j - 1] + 1,
                        // 3. 第一個字串和扣掉最後一個字的第二個字串所算出的distance
                        distance[i - 1][j] + 1
                    );
            }
        }
    }
    // 回傳 Levenshitein Distance
    return distance[str1.length()][str2.length()];
}

// Intent: 找出三個unsigned中的最小值
// Pre: 三個unsigned
// Post: 回傳最小值
unsigned minimum(unsigned value1, unsigned value2, unsigned value3)
{
    unsigned min = value1;
    if (value2 < min)
    {
        min = value2;
    }
    if (value3 < min)
    {
        min = value3;
    }
    return min;
}