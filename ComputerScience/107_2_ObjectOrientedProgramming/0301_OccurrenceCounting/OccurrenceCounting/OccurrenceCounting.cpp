#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
enum ColumnTitle { N, COUNT };
void occurrenceCounting(string, vector<vector<int>>&);
int main() {
    const string FILENAME = "intArray.txt";
    vector<vector<int>> list(2);

    // Calling the function
    occurrenceCounting(FILENAME, list);

    // Printing the result
    cout << "N count" << endl;
    for (unsigned int i = 0; i < list[N].size(); i++)
    {
        cout << list[N][i] << " " << list[COUNT][i] << endl;
    }
    system("pause");
}
// Intent: To Compute the occurrence of the integers
// Pre: A file of integers and a 2-dimensional array of integer
// Post: A sorted list and counts of integers
void occurrenceCounting(string filename, vector<vector<int>>& list) {
    // Opening the file
    fstream file;
    file.open(filename);
    do
    {
        // Reading the file
        int currentInteger;
        file >> currentInteger;

        // Finding the index to insert a new data
        unsigned int index = 0;
        while (index < list[N].size() && currentInteger < list[N][index])
        {
            index++;
        }

        // Inserting a new data
        if (list[N].size() == 0 || index == list[N].size())
        {
            list[N].push_back(currentInteger);
            list[COUNT].push_back(1);
        }
        else if (currentInteger == list[0][index])
        {
            list[COUNT][index]++;
        }
        else if (currentInteger > list[0][index])
        {
            list[N].insert(list[N].begin() + index, currentInteger);
            list[COUNT].insert(list[COUNT].begin() + index, 1);
        }
    } while (!file.eof());

    // Closing the file
    file.close();
}