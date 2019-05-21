#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Pre: An integer
// Intent: To align an integer whose digits are less than 10 to the right
// Post: The result printed
int main() {
    string input;
    do {
        cin >> input;
        if (input.length() < 10)
        {
            right;
        }
        else
        {
            left;
        }
        cout << setw(10) << input << endl;
        
    }
    while (input.length() > 2 || stoi(input) != EOF);
}