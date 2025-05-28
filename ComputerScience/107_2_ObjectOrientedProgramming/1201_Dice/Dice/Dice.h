#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <time.h>

class Dice
{
public:
    Dice();
    Dice(int numSides);
    virtual int rollDice() const;
protected:
    int numSides;
};

int rollTwoDice(const Dice& die1, const Dice& die2);

#endif // !DICE_H