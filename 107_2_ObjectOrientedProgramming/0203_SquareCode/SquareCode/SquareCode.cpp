#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
// Pre: A string without space inputted
// Intent: To transform a linear string into square code
// Post: The result printed
int main() {
    string input;
    // Inputting a string
    while (cin >> input)
    {
        // Computing the amount of line
        unsigned int lineAmount = static_cast<int>(ceil(sqrt(input.length())));

        // Printing the square
        for (unsigned int i = 0; i < lineAmount; i++)
        {
            for (unsigned int j = i; j < input.length(); j += lineAmount)
            {
                cout << input[j];
            }
            cout << endl;
        }
    }
}