#include "HumanPlayer.h"

// Intent: 猜答案
// Pre: 範圍
// Post: 回傳輸入的值
int HumanPlayer::getGuess(pair<int, int> bound)
{
    cout << bound.first << "~" << bound.second << endl;
    int guess;
    cin >> guess;
    return guess;
}