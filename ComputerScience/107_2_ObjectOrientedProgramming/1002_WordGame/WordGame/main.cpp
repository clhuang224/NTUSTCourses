#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef struct element
{
    unsigned x = 0;
    unsigned y = 0;
    char letter = 0;
}
element;

bool wordGame(vector<vector<element>>, string);
bool findPath(vector<vector<element>> grid, vector<element> possibleChar, string remainingWord);

int main() {

    
    vector<string> list;
    fstream file("words.txt");
    if (file.fail() != true)
    {
        string word;
        while (file >> word)
        {
            list.push_back(word);
        }
    }
    // 關檔
    file.close();
    while (!cin.eof())
    {
        vector<vector<element>> grid(6, vector<element>(6));
        for (unsigned j = 1; j < grid.size() - 1; j++)
        {
            for (unsigned i = 1; i < grid[0].size() - 1; i++)
            {

                char temp = getchar();
                grid[i][j] = { i,j,temp };

            }
            getchar();
        }
        for (string word : list)
        {
            if (wordGame(grid, word) == true)
            {
                cout << word << endl;
            }
        }
    }
}

// Intent: 算出字串是否存在在陣列中
// Pre: 二維陣列、字串
// Post: 回傳真假值
bool wordGame(vector<vector<element>> grid, string word)
{
    vector<element> possibleStart;
    for (unsigned j = 1; j < grid.size() - 1; j++)
    {
        for (unsigned i = 1; i < grid[0].size() - 1; i++)
        {
            if (grid[i][j].letter == word[0])
            {
                possibleStart.push_back(grid[i][j]);
            }
        }
    }
    return findPath(grid, possibleStart, word);

}

// Intent: 算出是否存在可走的路徑
// Pre: 二維陣列、可走的單步、字串
// Post: 回傳真假值
bool findPath(vector<vector<element>> grid, vector<element> possibleChar, string remainingWord)
{
    if (remainingWord.length() == 1)
    {
        for (unsigned i = 0; i < possibleChar.size(); i++)
        {
            if (possibleChar[i].letter == remainingWord[0])
            {
                return true;
            }
        }
        return false;
    }
    else if (remainingWord.length() > 1)
    {
        if (possibleChar.size() == 0)
        {
            return false;
        }
        else
        {
            bool result = false;
            for (unsigned i = 0; i < possibleChar.size(); i++)
            {
                vector<vector<element>> newGrid(6, vector<element>(6));
                for (unsigned j = 1; j < grid.size() - 1; j++)
                {
                    for (unsigned i = 1; i < grid[0].size() - 1; i++)
                    {
                        newGrid[i][j] = grid[i][j];
                    }
                }
                newGrid[possibleChar[i].x][possibleChar[i].y].letter = 0;

                vector<element> newPossibleChar;
                unsigned a = possibleChar[i].x, b = possibleChar[i].y;
                if (newGrid[a][b - 1].letter == remainingWord[1]) // 上
                {
                    newPossibleChar.push_back(newGrid[a][b - 1]);
                }
                if (newGrid[a][b + 1].letter == remainingWord[1]) // 下
                {
                    newPossibleChar.push_back(newGrid[a][b + 1]);
                }
                if (newGrid[a - 1][b].letter == remainingWord[1]) // 左
                {
                    newPossibleChar.push_back(newGrid[a - 1][b]);
                }
                if (newGrid[a + 1][b].letter == remainingWord[1]) // 右
                {
                    newPossibleChar.push_back(newGrid[a + 1][b]);
                }
                if (newGrid[a - 1][b - 1].letter == remainingWord[1]) // 左上
                {
                    newPossibleChar.push_back(newGrid[a - 1][b - 1]);
                }
                if (newGrid[a - 1][b + 1].letter == remainingWord[1]) // 左下
                {
                    newPossibleChar.push_back(newGrid[a - 1][b + 1]);
                }
                if (newGrid[a + 1][b + 1].letter == remainingWord[1]) // 右上
                {
                    newPossibleChar.push_back(newGrid[a + 1][b + 1]);
                }
                if (newGrid[a + 1][b - 1].letter == remainingWord[1]) // 右下
                {
                    newPossibleChar.push_back(newGrid[a + 1][b - 1]);
                }
                result = result || findPath(newGrid, newPossibleChar, remainingWord.substr(1, remainingWord.length() - 1));
            }
            return result;
        }
    }
    else
    {
        return true;
    }

}

