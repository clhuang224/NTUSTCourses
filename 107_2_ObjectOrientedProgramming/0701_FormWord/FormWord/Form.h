#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Form
{
private:
    string input;
    string fileName;
    vector<string> result;
public:
    Form();
    void SetInputWord(string);
    void ProcessInputWord();
    void SetFileName(string);
    void Load_CompaerWord();
    void PrintFoundWords();
};