#include <iostream>
#include <string>
using namespace std;
class Atoi {
private:
    string beTrans;
    char sign;
public:
    Atoi();
    Atoi(string);
    void SetString(string);
    const string GetString();
    int Length();
    bool IsDigital();
    int StringToInteger();
};

