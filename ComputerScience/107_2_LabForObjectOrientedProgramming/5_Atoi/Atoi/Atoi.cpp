#include "Atoi.h"

//Intent: 初始化
//Pre: 宣告Atoi物件
//Post: 初始化完成
Atoi::Atoi()
{
    beTrans = "";
    sign = '+';
}

//Intent: 初始化、處理正負號
//Pre: 宣告Atoi物件、string
//Post: 若包含負號，sign會存成'-'，並擷取負號後的字串放入beTrans
Atoi::Atoi(string s)
{
    if (s[0] == '-')
    {
        beTrans = s.substr(1,s.length()-1);
        sign = '-';
    }
    else
    {
        beTrans = s;
        sign = '+';
    }
}

//Intent: 修改字串
//Pre: Atoi物件、string
//Post: 若字串包含負號，sign會存成'-'，並擷取負號後的字串放入beTrans
void Atoi::SetString(string s)
{
    if (s[0] == '-')
    {
        beTrans = s.substr(1, beTrans.length() - 1);
        sign = '-';
    }
    else
    {
        beTrans = s;
        sign = '+';
    }
}

//Intent: 找出數字部分長度
//Pre: Atoi物件
//Post: 回傳beTrans長度
int Atoi::Length()
{
    return beTrans.length();
}

//Intent: 檢查字串是否均為數字
//Pre: Atoi物件
//Post: 回傳真假值
bool Atoi::IsDigital()
{
    for (unsigned i = 0; i<beTrans.length();i++)
    {
        if (beTrans[i] < 48 || beTrans[i] > 57)
        {
            return false;
        }
    }
    return true;
}

//Intent: 將物件所代表的數值轉為int
//Pre: Atoi物件
//Post: 回傳int
int Atoi::StringToInteger()
{
    int result = 0;
    unsigned j = 1;
    for (int i = beTrans.length()-1; i >= 0; i--)
    {
        result += (static_cast<int>(beTrans[i])-48) * j;
        j *= 10;
    }
    if (sign == '-')
    {
        return 0 - result;
    }
    else
    {
        return result;
    }
}