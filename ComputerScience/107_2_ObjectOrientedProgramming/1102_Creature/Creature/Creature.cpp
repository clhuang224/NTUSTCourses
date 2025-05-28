#include "Creature.h"


// Intent: initialize
// Pre: Creature created
// Post: initialized
Creature::Creature(int newType, int newStrength, int newHitpoints)
{
    type = newType;
    strength = newStrength;
    hitpoints = newHitpoints;
}

// Intent: get species
// Pre: Creature
// Post: return the string of species
string Creature::getSpecies()
{
    switch (type)
    {
    case 0: return "Human";
    case 1: return "Cyberdemon";
    case 2: return "Balrog";
    case 3: return "Elf";
    }
    return "Unknown";
}

// Intent: access member data
// Pre: Creature
// Post: return member data
int Creature::getType()
{
    return type;
}
int Creature::getStrength()
{
    return strength;
}
int Creature::getHitpoints()
{
    return hitpoints;
}

// Intent: mutate member data
// Pre: new data
// Post: member data changed
void Creature::setType(int newType)
{
    type = newType;
}
void Creature::setStrength(int newStrength)
{
    strength = newStrength;
}
void Creature::setHitpoints(int newHitpoints)
{
    hitpoints = newHitpoints;
}

// Intent: get damage
// Pre: Creature
// Post: return 1~strength
int Creature::getDamage()
{
    int damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
}