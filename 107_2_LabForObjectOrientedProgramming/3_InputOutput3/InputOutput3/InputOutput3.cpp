#include <iostream>
#include <iomanip>
using namespace std;
// Intent: To print a value by specific format
// Pre: A value, the total length of the output, the length of the decimal part, and the character to fill spaces
// Post: The result printed
int main() {
    double x;
    unsigned int m, n;
    char c;
    while(1)
    {
        // Inputting datas
        cin >> x >> m >> n >> c;

        // No need to showpoint if n is 0
        if (n == 0)
        {
            cout << noshowpoint;
        }
        else
        {
            cout << showpoint;
        }

        // Printing result
        cout << setw(m) << setprecision(n) << fixed << setfill(c) << right << x << endl;
    }
}