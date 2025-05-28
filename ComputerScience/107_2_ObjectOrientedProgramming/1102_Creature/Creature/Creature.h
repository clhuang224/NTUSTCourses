#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
using namespace std;

class Creature
{
private:
    int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf 
    int strength; // How much damage we can inflict 
    int hitpoints; // How much damage we can sustain 
    string getSpecies(); // Returns type of species 
public:
    Creature(int = 0, int = 10, int = 10); // Initialize to human, 10 strength, 10 hit points

    // Also add appropriate accessor and mutator functions for type, strength, and hit points
    int getType();
    int getStrength(); 
    int getHitpoints();

    void setType(int);
    void setStrength(int);
    void setHitpoints(int);
    
    int getDamage(); // Returns amount of damage this creature inflicts in one round of combat 
};

#endif // !CREATURE_H


