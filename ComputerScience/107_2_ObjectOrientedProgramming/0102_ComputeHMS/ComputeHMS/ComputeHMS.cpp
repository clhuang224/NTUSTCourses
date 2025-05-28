#include<iostream>
using namespace std;
// Intent: To compute the number of hours, minutes, and seconds that correspond to the input integer
// Post: Result printed
int main() {
	long long int input, hour, minute, second;
	const int SECONDS_PER_MINUTE = 60, MINUTES_PER_HOUR = 60;

	// Inputting the number
	cin >> input;

	// Computing the number of hours, minutes, and seconds
	hour = input / SECONDS_PER_MINUTE / MINUTES_PER_HOUR;
	minute = input / SECONDS_PER_MINUTE % MINUTES_PER_HOUR;
	second = input % SECONDS_PER_MINUTE;

	// Printing the result
	cout << hour << " hours " << minute << " minutes and " << second << " seconds";
}