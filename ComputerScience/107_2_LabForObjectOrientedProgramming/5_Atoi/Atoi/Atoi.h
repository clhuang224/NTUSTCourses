#include <iostream>
#include <string>
using namespace std;
#pragma once
class Atoi
{
private:
    string beTrans;
    char sign;
public:
    Atoi();
    Atoi(string s);
    void SetString(string s);
    int Length();
    bool IsDigital();
    int StringToInteger();
};