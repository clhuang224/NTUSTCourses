#include "PrimeNumber.h"

// Intent: ﹍て
// Pre: PrimeNumberン
// Post: value﹍て1
PrimeNumber::PrimeNumber()
{
    value = 1;
}

// Intent: ﹍て
// Pre: PrimeNumberンunsigned把计
// Post: value﹍てunsigned把计
PrimeNumber::PrimeNumber(unsigned newValue)
{
    value = newValue;
}

// Intent: 眔value
// Pre: PrimeNumberン
// Post: 肚value
unsigned PrimeNumber::get()
{
    return value;
}

// Intent: ﹚竡PrimeNumberprefix ++
// Pre: PrimeNumberン
// Post: value糤借计肚value
PrimeNumber PrimeNumber::operator++ ()
{
    if (value < 3)
    {
        value++;
        return PrimeNumber(value);
    }
    else
    {
        if (isPrime(value) == false)
        {
            value++;
        }
        else
        {
            value += 2;
        }
        while (isPrime(value) == false)
        {
            value += 2;
        }
        return PrimeNumber(value);
    }
}

// Intent: ﹚竡PrimeNumberpostfix ++
// Pre: PrimeNumberン
// Post: value糤借计肚セvalue
PrimeNumber PrimeNumber::operator++ (int)
{
    unsigned temp = value;
    if (value < 3)
    {
        value++;
        return PrimeNumber(temp);
    }
    else
    {
        if (isPrime(value) == false)
        {
            value++;
        }
        else
        {
            value += 2;
        }
        while (isPrime(value) == false)
        {
            value += 2;
        }
        return PrimeNumber(temp);
    }
}

// Intent: ﹚竡PrimeNumberprefix --
// Pre: PrimeNumberン
// Post: value搭ぶ玡借计
PrimeNumber PrimeNumber::operator-- ()
{
    if (value == 1)
    {
        return PrimeNumber();
    }
    else if (value < 4)
    {
        value--;
        return PrimeNumber(value);
    }
    else
    {
        if (isPrime(value) == false)
        {
            value--;
        }
        else
        {
            value -= 2;
        }
        while (isPrime(value) == false)
        {
            value -= 2;
        }
        return PrimeNumber(value);
    }
}

// Intent: ﹚竡PrimeNumberpostfix --
// Pre: PrimeNumberン
// Post: value搭ぶ玡借计肚セvalue
PrimeNumber PrimeNumber::operator-- (int)
{
    unsigned temp = value;
    if (value == 1)
    {
        return PrimeNumber();
    }
    else if(value < 4)
    {
        value--;
        return PrimeNumber(temp);
    }
    else
    {
        if (isPrime(value) == false)
        {
            value--;
        }
        else
        {
            value -= 2;
        }
        while (isPrime(value) == false)
        {
            value -= 2;
        }
        return PrimeNumber(temp);
    }
}

// Intent: 耞琌借计
// Pre: unsigned把计
// Post: 肚痷安
bool isPrime(unsigned value)
{
    for (unsigned i = 3; i < static_cast<unsigned>(sqrt(value)) + 1; i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}