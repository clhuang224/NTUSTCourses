#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
// Intent: To print a list by format
// Pre: A string and two integer separated by space in a line
// Post: The result printed
int main() {
    while (1)
    {
        long amount;
        cin >> amount;
        vector<string> name(amount);
        vector<long> salary(amount);
        vector<long> bonus(amount);

        int nameLength, salaryLength, bonusLength;

        for (unsigned i = 0; i < amount; i++)
        {
            // Storing datas into each vector
            cin >> name[i] >> salary[i] >> bonus[i];

            // Counting the width of each column
            if (i == 0)
            {
                nameLength = name[i].length();
                salaryLength = to_string(salary[i]).length();
                bonusLength = to_string(bonus[i]).length();
            }
            else
            {
                if (name[i].length() > nameLength)
                {
                    nameLength = name[i].length();
                }
                if (to_string(salary[i]).length() > salaryLength)
                {
                    salaryLength = to_string(salary[i]).length();
                }
                if (to_string(bonus[i]).length() > bonusLength)
                {
                    bonusLength = to_string(bonus[i]).length();
                }
            }
        }

        // Printing result
        for (unsigned i = 0; i < amount; i++)
        {
            cout << right << setw(nameLength) << name[i] << "|"
                << setw(salaryLength + 2) << salary[i] << "|"
                << setw(bonusLength + 2) << bonus[i] << endl;
        }
    }
}