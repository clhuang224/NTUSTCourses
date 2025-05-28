#include "Elf.h"

// Intent: initialize
// Pre: Elf created
// Post: initialized
Elf::Elf(int newStrength, int newHitpoints) :Creature(3, newStrength, newHitpoints)
{
}

// Intent: get damage
// Pre: Elf
// Post: return 1~strength + extra double by 10%
int Elf::getDamage()
{
    int damage = Creature::getDamage();
    if ((rand() % 10==0))
    {
        cout << "Magical attack inflicts " << damage <<" additional damage points!" << endl;
        return damage * 2;
    }
    else
    {
        return damage;
    }
}
