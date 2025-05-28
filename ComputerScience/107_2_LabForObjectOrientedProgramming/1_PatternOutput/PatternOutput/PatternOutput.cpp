#include <iostream>
using namespace std;
// Intent: To print a pattern
// Post: The result printed
int main() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7 - i; j++)
        {
            cout << ' ';
        }
        cout << '*' << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        cout << '*';
        for (int j = 0; j < 3 - 2 * i; j++)
        {
            cout << ' ';
        }
        cout << ((i == 2) ? "" : "*") << endl;
    }
}