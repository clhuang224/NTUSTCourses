#include <iostream>
#include <string>
using namespace std;
#pragma once
class HotDogStand
{
public:
    HotDogStand(string, unsigned int = 0);
    void justSold();
    unsigned int thisStandSoldAmount();
    static unsigned int allStandSoldAmount();
    void print();
private:
    string id;
    unsigned int sold;
    static unsigned int totalSold;
};

