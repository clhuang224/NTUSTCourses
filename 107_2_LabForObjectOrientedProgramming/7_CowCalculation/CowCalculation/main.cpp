#include <iostream>
#include <string>
using namespace std;
bool followHypothesis();
void chooseOperator(string, string&, string);
unsigned cowToDec(string);
string decToCow(unsigned);
int main() {

    while (!cin.eof())
    {
        unsigned testAmount;
        cin >> testAmount;
        cout << "COWCULATIONS OUTPUT" << endl;
        for (unsigned i = 0; i < testAmount; i++)
        {
            if (followHypothesis())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        cout << "END OF OUTPUT" << endl;
    }

}

// Intent: 測試一筆資料是否符合假說
// Pre: function中輸入字串、運算子與結果
// Post: 回傳真假值
bool followHypothesis()
{
    // 輸入兩筆字串
    string num1, num2;
    cin >> num1 >> num2;

    // 進行三次運算
    for (unsigned i = 0; i < 3; i++)
    {
        string operatorCharacter;
        cin >> operatorCharacter;
        chooseOperator(num1, num2, operatorCharacter);
    }

    // 將運算結果補滿八位元
    for (unsigned i = 0; num2.length() < 8; i++)
    {
        num2.insert(0, "V");
    }

    // 輸入實際結果
    string result;
    cin >> result;

    // 比對運算結果和實際結果並回傳真假值
    if (num2 == result)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Intent: 將兩個字串依據所選運算子進行運算
// Pre: 兩個字串及一個運算子
// Post: num2被改變
void chooseOperator(string num1, string& num2, string operatorCharacter)
{
    switch (operatorCharacter[0])
    {
    case 'A':
        // 將兩個字串轉為十進位數字相加後轉回cow symbol
        num2 = decToCow(cowToDec(num1) + cowToDec(num2));
        break;
    case 'R':
        // 向右位移
        num2.pop_back();
        num2.insert(0, 1, 'V');
        break;
    case 'L':
        // 向左位移
        num2.push_back('V');
        if (num2.length() >= 8)
        {
            num2 = num2.substr(num2.size() - 8, num2.size());
        }
        break;
    }
}

// Intent: 將cow symbol轉為十進位數字
// Pre: 一個string參數
// Post: 回傳十進位數字
unsigned cowToDec(string cow)
{
    unsigned result = 0, pow = 1;
    for (int i = static_cast<int>(cow.length() - 1); i >= 0; i--)
    {
        switch (cow[i])
        {
        case 'U':
            result += 1 * pow;
            break;
        case 'C':
            result += 2 * pow;
            break;
        case 'D':
            result += 3 * pow;
            break;
        }
        pow *= 4;
    }
    return result;
}

// Intent: 將十進位數字轉為cow symbol
// Pre: 一個unsigned
// Post: 回傳cow symbol字串
string decToCow(unsigned dec)
{
    string result = "";
    while (dec > 0)
    {
        unsigned current = dec % 4;
        switch (current)
        {
        case 0:
            result.insert(0, 1, 'V');
            break;
        case 1:
            result.insert(0, 1, 'U');
            break;
        case 2:
            result.insert(0, 1, 'C');
            break;
        case 3:
            result.insert(0, 1, 'D');
            break;
        }
        dec /= 4;
    }
    if (result == "")
    {
        return "V";
    }
    else
    {
        return result;
    }
}