#include "Part.h"

// Intent: ﹍て
// Pre: Partンネ嘿把计场嘿场计秖
// Post: ﹍てЧΘ
Part::Part(string myCreature, string newName, unsigned newAmount)
{
    creature = myCreature;
    name = newName;
    amount = newAmount;
}

// Intent: 眔场嘿
// Pre: Partン
// Post: 肚场嘿
string Part::getName()
{
    return name;
}

// Intent: 眔场计秖
// Pre: Partン
// Post: 肚场计秖
unsigned Part::getAmount()
{
    return amount;
}

// Intent: ﹚竡Partン=
// Pre: Partン
// Post: amount穝把计糶魁
void Part::operator=(unsigned value)
{
    if (amount != value)
    {
        Diary::writeDiary(creature, name, amount, value);
        amount = value;
    }
}

// Intent: ﹚竡Partン+=
// Pre: Partン
// Post: amount穝糶魁
void Part::operator+=(int value)
{
    if (amount != (amount + value))
    {
        Diary::writeDiary(creature, name, amount, amount + value);
    }

    amount += value;
}

// Intent: ﹚竡Partン-=
// Pre: Partン
// Post: amount穝糶魁
void Part::operator-=(int value)
{
    if (amount != (amount - value))
    {
        Diary::writeDiary(creature, name, amount, amount - value);
    }
    amount -= value;
}