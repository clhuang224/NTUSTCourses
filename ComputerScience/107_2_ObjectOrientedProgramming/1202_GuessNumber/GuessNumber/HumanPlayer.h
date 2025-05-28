#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
using std::cin;
class HumanPlayer :
    public Player
{
public:
    virtual int getGuess(pair<int, int>);
};

#endif // !HUMANPLAYER_H
