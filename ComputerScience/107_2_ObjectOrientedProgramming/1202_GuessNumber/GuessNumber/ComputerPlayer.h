#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
class ComputerPlayer :
    public Player
{
public:
    virtual int getGuess(pair<int, int>);
};

#endif // !COMPUTERPLAYER_H


