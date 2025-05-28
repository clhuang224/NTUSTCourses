#include "Atoi.h"

// Intent: ﹍てAtoiン
// Pre: Atoiン
// Post: beTransのsign﹍じ
Atoi::Atoi()
{
    beTrans = "";
    sign = '\0';
}

// Intent: ﹍てAtoiン
// Pre: Atoiン
// Post: beTrans﹍s计场だsign﹍タ璽腹
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

// Intent: 砞﹚Atoiン
// Pre: Atoiンの穝﹃
// Post: beTrans穝s计场だsign穝タ璽腹
void Atoi::SetString(string s)
{
    if (s[0] == '-')
    {
        beTrans = s.substr(1, s.length() - 1);
        sign = '-';
    }
    else
    {
        beTrans = s;
        sign = '+';
    }
}

// Intent: 眔Atoi﹃
// Pre: Atoiン
// Post: 肚Ч俱﹃
const string Atoi::GetString()
{
    if (sign == '-')
    {
        return sign + beTrans;
    }
    else
    {
        return beTrans;
    }
}

// Intent: 眔计场だ
// Pre: Atoiン
// Post: 肚beTrans
int Atoi::Length()
{
    return beTrans.length();
}

// Intent: 耞﹃琌计
// Pre: Atoiン
// Post: 肚痷安
bool Atoi::IsDigital()
{
    if (sign != '+' && sign != '-')
    {
        return false;
    }
    for (char c : beTrans)
    {
        if (c < 48 || 57 < c)
        {
            return false;
        }
    }
    return true;
}

// Intent: 盢﹃锣传int
// Pre: Atoiン
// Post: 肚int
int Atoi::StringToInteger()
{
    int result = 0, p = 1;
    for (int i = static_cast<int>(beTrans.length() - 1); i >= 0; i--)
    {
        result += (beTrans[i] - 48) * p;
        p *= 10;
    }
    if (sign == '-')
    {
        result = 0 - result;
    }
    return result;
}