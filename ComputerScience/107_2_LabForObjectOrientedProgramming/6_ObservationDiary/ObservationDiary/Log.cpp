#include "Log.h"

// Intent: ﹍て
// Pre: Logンネ嘿把计场嘿把计玡计
// Post: ﹍てЧΘ
Log::Log(string newCreature,string newPart,unsigned newBefore,unsigned newAfter)
{
    creature = newCreature;
    part = newPart;
    before = newBefore;
    after = newAfter;
}

// Intent: 眔ネ嘿
// Pre: Pageン
// Post: 肚creature
string Log::getCreature()
{
    return creature;
}

// Intent: 眔场嘿
// Pre: Pageン
// Post: 肚part
string Log::getPart()
{
    return part;
}

// Intent: 眔э跑玡计
// Pre: Pageン
// Post: 肚before
unsigned Log::getBefore()
{
    return before;
}

// Intent: 眔э跑计
// Pre: Pageン
// Post: 肚after
unsigned Log::getAfter()
{
    return after;
}