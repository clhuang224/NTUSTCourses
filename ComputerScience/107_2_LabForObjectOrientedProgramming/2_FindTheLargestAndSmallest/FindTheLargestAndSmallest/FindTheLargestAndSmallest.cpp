#include <iostream>
using namespace std;
// Intent: To find the largest and the smallest integer in a line
// Pre: Four integers separated by space in a line
// Post: The result printed
int main() {
    while (1)
    {
        // Inputing the first value
        long smallest, largest;
        cin >> smallest;
        largest = smallest;

        // Finding the largest and the smallest
        for (unsigned i = 0; i < 3; i++)
        {
            long current;
            cin >> current;
            if (current > largest)
            {
                largest = current;
            }
            else if (current < smallest)
            {
                smallest = current;
            }
        }
        // Printing the result
        cout << "Largest: " << largest << endl << "Smallest: " << smallest << endl;
    }
}