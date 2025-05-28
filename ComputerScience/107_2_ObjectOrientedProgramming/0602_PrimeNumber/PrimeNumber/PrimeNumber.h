#include <iostream>
using namespace std;
#pragma once
class PrimeNumber
{
public:
    PrimeNumber();
    PrimeNumber(unsigned);
    unsigned get();
    PrimeNumber operator++ ();
    PrimeNumber operator++ (int);
    PrimeNumber operator-- ();
    PrimeNumber operator-- (int);
private:
    unsigned value;
};

bool isPrime(unsigned);