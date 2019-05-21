#include "LoadedDice.h"

LoadedDice::LoadedDice(int numSides) : Dice(numSides)
{
}

int LoadedDice::rollDice() const
{
    if ((rand() % 2) == 0)
    {
        return Dice::rollDice();
    }
    else
    {
        return numSides;
    }
}