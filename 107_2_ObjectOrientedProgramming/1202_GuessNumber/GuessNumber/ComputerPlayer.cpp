#include "ComputerPlayer.h"

// Intent: 猜答案
// Pre: 範圍
// Post: 回傳範圍內的隨機數字
int ComputerPlayer::getGuess(pair<int, int> bound)
{
    cout << bound.first << "~" << bound.second << endl;
    int guess = (rand() % (bound.second - bound.first + 1)) + bound.first;
    cout << guess << endl;
    return guess;
}