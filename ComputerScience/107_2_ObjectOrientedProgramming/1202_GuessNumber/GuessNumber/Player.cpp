#include "Player.h"

// Intent: 檢查有沒有猜中
// Pre: 猜測、答案、範圍
// Post: 答對回傳true、答錯回傳false並修改範圍
bool checkForWin(int guess, int answer, pair<int, int>& bound)
{
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess)
    {
        if (bound.second > guess)
        {
            bound.second = guess;
        }
        cout << "Your guess is too high." << endl;
        return false;
    }
    else
    {
        if (bound.first < guess)
        {
            bound.first = guess;
        }
        cout << "Your guess is too low." << endl;
        return false;
    }
}

// Intent: 執行一場遊戲
// Pre: 兩個player
// Post: 印出過程
void play(Player &player1, Player &player2)
{
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;
    pair<int, int> bound = { 0,99 };

    while (!win)
    {
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess(bound);
        win = checkForWin(guess, answer, bound);
        if (win) return;

        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess(bound);
        win = checkForWin(guess, answer, bound);
    }
}
