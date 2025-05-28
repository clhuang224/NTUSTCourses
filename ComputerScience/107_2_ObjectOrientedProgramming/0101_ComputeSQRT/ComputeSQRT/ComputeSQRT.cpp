#include <iostream>
#include <iomanip>
using namespace std;
// Intent: To compute the square root of input
// Post: The square root of input printed
int main() {
	double input, guess, previous, revise;
	const double BOUNDARY = 0.01;
	// Inputting a value
	cin >> input;

	// Babylonian algorithm
	guess = input / 2.0;
	previous = input;
	while (previous - guess >= BOUNDARY)
	{
		revise = input / guess;
		previous = guess;
		guess = (guess + revise) / 2.0;
	}

	// Printing the result
	cout << fixed << showpoint << setprecision(2) << guess;
}