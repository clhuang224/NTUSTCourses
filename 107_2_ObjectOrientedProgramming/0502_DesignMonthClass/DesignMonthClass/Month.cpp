#include "Month.h"

// Intent: 以int初始化Month物件
// Pre: 1-12的數字
// Post: 初始化
Month::Month(unsigned int newMonth)
{
    month = newMonth;
}

// Intent: 以字元初始化Month物件
// Pre: 月份的前三個字元
// Post: 初始化
Month::Month(char first, char second, char third)
{
    month = monthInt(first, second, third);
}

// Intent: 使用者更改month的值
// Pre: 使用者輸入1-12的數字
// Post: month的值改變
void Month::inputInt()
{
    cin >> month;
}

// Intent: 使用者更改month的值
// Pre: 使用者輸入月份前三個字母
// Post: month的值改變
void Month::inputStr()
{
    char first, second, third;
    cin >> first >> second >> third;
    month = monthInt(first, second, third);
}

// Intent: 印出month的值
// Pre: Month物件
// Post: 印出month的值
void Month::outputInt()
{
    cout << month;
}

// Intent: 印出對應month值的月份前三個字母
// Pre: Month物件
// Post: 印出三個字母
void Month::outputStr()
{
    const char* MONTH_NAME[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep","Oct","Nov","Dec" };
    cout << MONTH_NAME[month - 1];
}

// Intent: 回傳Month物件的下一個月份
// Pre: Month物件
// Post: 回傳下個月的int
unsigned int Month::nextMonth()
{
    if (month < 12)
    {
        return month + 1;
    }
    else
    {
        return 1;
    }
}

// Intent: 以字元找出對應的月份int
// Pre: 月份的前三個字母
// Post: 回傳數字
unsigned int Month::monthInt(char first, char second, char third)
{
    switch (first)
    {
    case 'J':
        if (second == 'a') // Jan
        {
            return 1;
        }
        else
        {
            if (third == 'n') // Jun
            {
                return 6;
            }
            else // Jul
            {
                return 7;
            }
        }
    case 'F': // Feb
        return 2;
    case 'M':
        if (second == 'a')
        {
            if (third == 'r') // Mar
            {
                return 3;
            }
            else if (third == 'y') // May
            {
                return 5;
            }
        }
    case 'A':
        if (second == 'p') // Apr
        {
            return 4;
        }
        else // Aug
        {
            return 8;
        }
    case 'S': // Sep
        return 9;
    case 'O': // Oct
        return 10;
    case 'N': // Nov
        return 11;
    case 'D': // Dec
        return 12;
    }
}