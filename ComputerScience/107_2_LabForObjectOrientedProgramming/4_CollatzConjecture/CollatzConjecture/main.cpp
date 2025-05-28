#include <iostream>
using namespace std;
long long findMaxCycleLength(long long i, long long j);
long long cycleLength(long long n);
int main() {
	long long i, j;
	cin >> i >> j;
	while (!cin.eof()) {
		cout << i << " " << j << " ";
		if (i > j)
		{
			swap(i, j);
		}
		cout << findMaxCycleLength(i, j) << endl;
		cin >> i >> j;
	}
}

// Intent: 尋找由i到j之間，最大的CycleLenth
// Pre: 兩個小於1000000的正整數
// Post: 回傳最大的CycleLength
long long findMaxCycleLength(long long i, long long j) {
	long long max = 0;
	for (; i <= j; i++)
	{
		long long temp = cycleLength(i);
		cout << temp << endl;
		if (temp > max)
		{
			max = temp;
		}
	}
	return max;
}

// Intent: 尋找一個正整數的CycleLenth
// Pre: 一個小於1000000的正整數
// Post: 回傳CycleLength
long long cycleLength(long long n) {
	static long long result = 1;
	// If N equals 1, end calculation
	if (n == 1)
	{
		long long temp = result++;
		result = 1;
		return temp;
	}
	// N/ 2 ,if N" is even number" 
	else if (n % 2 == 0)
	{
		result++;
		return cycleLength(n / 2);
	}
	// N / 2, if N" is even number"
	else
	{
		result++;
		return cycleLength(n * 3 + 1);
	}
}