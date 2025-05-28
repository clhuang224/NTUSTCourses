#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// Pre: The amount of datas and the datas inputted
// Intent: To compute the average and the standard deviation
// Post: The result printed
int main() {
	double amount, average = 0, standardDeviation = 0;
	// Inputting
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		int data;
		// Inputting
		cin >> data;
		average += data;
		standardDeviation += pow(data, 2);
	}
	average /= amount;
	standardDeviation = sqrt(standardDeviation / amount - pow(average, 2));

	// Printing the result
	cout << "Average:" << average << "\tStandard deviation:" << standardDeviation << endl;
}