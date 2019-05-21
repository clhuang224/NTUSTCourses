#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <time.h>
#include <utility>

using std::cout;
using std::endl;
using std::pair;

class Player
{
public:
    virtual int getGuess(pair<int,int>) = 0;
};

bool checkForWin(int, int, pair<int, int>&);
void play(Player &, Player &);

#endif // !PLAYER_H

