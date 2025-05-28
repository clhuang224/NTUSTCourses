#pragma once
#include "Demon.h"
class Balrog :
    public Demon
{
public:
    Balrog(int = 10, int = 10);
    int getDamage();
};

