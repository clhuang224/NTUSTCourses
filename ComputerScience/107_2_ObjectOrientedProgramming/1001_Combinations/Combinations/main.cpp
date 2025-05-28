#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
void PrintCombination(int*, int, int);
string unsignedToBinaryString(unsigned, unsigned);
#define NULL 0

#define ELEMENTS_FOR_COMBINATION 5	//i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4

int main(void)
{
    int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

    //Get all elements for combination
    for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
        arrayPtr[i] = i + 1;

    PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);

    if (arrayPtr != NULL)
        delete[] arrayPtr;

    system("pause");
    return 0;
}

// Intent: 印出所有組合
// Pre: 陣列指標、n、k
// Post: 印出結果
void PrintCombination(int* arrayPrt, int n, int k)
{
    unsigned all = 1;
    for (unsigned i = 0; i < static_cast<unsigned>(n); i++)
    {
        all *= 2;
    }
    all--;

    // 找到所有可能
    vector<string> bitSwitch;
    for (unsigned i = all; i > 0; i--)
    {
        string current = unsignedToBinaryString(i,n);
        int amount = 0;
        for (unsigned j = 0; j < static_cast<unsigned>(n); j++)
        {
            if (current[current.length() - 1 - j] == '1')
            {
                amount++;
            }
        }
        if (amount == k)
        {
            bitSwitch.push_back(current);
        }
    }

    // 印出所有可能
    for (unsigned i = 0; i < bitSwitch.size(); i++)
    {
        bool first = true;
        for (unsigned j = 0; j < static_cast<unsigned>(n); j++)
        {
            if (bitSwitch[i][bitSwitch[i].length() - n + j] == '1')
            {
                cout << (first ? "" : " ") << arrayPrt[j];
                first = false;
            }
        }
        cout << endl;
    }
}

// Intent: 將數值轉為二進位字串
// Pre: 數值、字串長度
// Post: 回傳字串
string unsignedToBinaryString(unsigned input, unsigned length)
{
    string result;

    while (input > 0)
    {
        result.insert(result.begin(), 1, static_cast<char>(input % 2+48));
        input /= 2;
    }
    while (result.length() < length)
    {
        result.insert(result.begin(), 1, '0');
    }
    return result;
}