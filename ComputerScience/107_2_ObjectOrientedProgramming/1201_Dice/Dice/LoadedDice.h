#ifndef LOADEDDICE_H
#define LOADEDDICE_H

#include <iostream>
#include "Dice.h"
class LoadedDice :
    public Dice
{
public:
    LoadedDice(int numSides = 6);

private:
    virtual int rollDice() const;
};

#endif // !LOADEDDICE_H

