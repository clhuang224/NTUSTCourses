#include <iostream>
using namespace std;

long unsigned GCD(long unsigned, long unsigned);

int main()
{
    while (!cin.eof())
    {
        // 块ㄢタ俱计
        long unsigned a, b;
        cin >> a >> b;

        // 块程そ计
        cout << GCD(a, b) << endl;
    }
}

// Intent: 璸衡程そ计
// Pre: ㄢタ俱计把计
// Post: 肚程そ计
long unsigned GCD(long unsigned a, long unsigned b)
{
    if (a != 0)
    {
        if (b != 0)
        {
            a %= b;
        }
        return GCD(b, a);
    }
    else
    {
        return b;
    }

}