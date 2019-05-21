#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void countTextBasedHistogram(string filename, vector<unsigned int>& countArray);
int main() {
    const string FILENAME = "grade.txt";
    vector<unsigned int> countArray(6, 0);

    // Calling the function
    countTextBasedHistogram(FILENAME, countArray);

    // Printing the result
    for (unsigned int i = 0; i < countArray.size(); i++)
    {
        cout << countArray[i] << " grade(s) of " << i << endl;
    }
}

// Intent: To count a text-based histogram
// Pre: A filename and an 1-dimentional vector
// Post: The vector revised
void countTextBasedHistogram(string filename, vector<unsigned int>& countArray) {
    // Reading the file
    fstream file;
    file.open(filename);

    // Counting
    unsigned int currentGrade;
    while (file >> currentGrade)
    {
        countArray[currentGrade]++;
    }

    // Closing the file
    file.close();
}