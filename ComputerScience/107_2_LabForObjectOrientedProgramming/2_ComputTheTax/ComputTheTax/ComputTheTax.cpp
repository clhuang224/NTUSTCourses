#include <iostream>
#include <iomanip>
using namespace std;
// Intent: To compute the tax according to the income
// Pre: A float representing the income
// Post: The tax printed
int main() {
    // Setting output format
    cout << fixed << showpoint << setprecision(2);
    while (1)
    {
        // incometing the income
        float income;
        cin >> income;
        if (income < 750)
        {
            cout << income * 0.01 << endl;
        }
        else if (income < 2250)
        {
            cout << 7.5 + (income - 750) * 0.02 << endl;
        }
        else if (income < 3750)
        {
            cout << 37.5 + (income - 2250) * 0.03 << endl;
        }
        else if (income < 5250)
        {
            cout << 82.5 + (income - 3750) * 0.04 << endl;
        }
        else if (income < 7000)
        {
            cout << 142.5 + (income - 5250) * 0.05 << endl;
        }
        else
        {
            cout << 230 + (income - 7000) * 0.06 << endl;
        }
    }

}