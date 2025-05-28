#pragma once
#include "Creature.h"
class Elf :
    public Creature
{
public:
    Elf(int = 10, int = 10);
    int getDamage();
};

