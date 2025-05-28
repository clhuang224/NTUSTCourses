#include <iostream>
using namespace std;
#pragma once
class Month
{
public:
    Month(unsigned int = 1);
    Month(char, char, char);
    void inputInt();
    void inputStr();
    void outputInt();
    void outputStr();
    unsigned int nextMonth();
private:
    unsigned int month;
    unsigned int monthInt(char first, char second, char third);
};