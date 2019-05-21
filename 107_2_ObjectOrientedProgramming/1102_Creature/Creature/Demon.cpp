#include "Demon.h"


// Intent: initialize
// Pre: Demon created
// Post: initialized
Demon::Demon(int newType, int newStrength, int newHitpoints):Creature(newType,newStrength, newHitpoints)
{
}

// Intent: get damage
// Pre: Demon
// Post: return 1~strength + extra 50 by 5%
int Demon::getDamage()
{
    int damage = Creature::getDamage();
    if ((rand() % 100 < 5))
    {
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        return damage + 50;
    }
    else
    {
        return damage;
    }
}