#pragma once
#include "Creature.h"
class Demon :
    public Creature
{
public:
    Demon(int, int, int);
    int getDamage();
};

