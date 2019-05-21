#include "Balrog.h"


// Intent: initialize
// Pre: Balrog created
// Post: initialized
Balrog::Balrog(int newStrength, int newHitpoints) :Demon(2, newStrength, newHitpoints)
{
}

// Intent: get damage
// Pre: Balrog
// Post: return double damage
int Balrog::getDamage()
{
    int damage1 = Creature::getDamage(), damage2 = (rand() % getStrength()) + 1;
    cout << "Balrog speed attack inflicts " << damage2 <<" additional damage points!" << endl;
    return damage1 + damage2;
}
