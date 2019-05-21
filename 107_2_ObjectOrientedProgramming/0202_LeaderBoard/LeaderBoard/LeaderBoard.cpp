#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void getHighScores(vector<string>* name, vector<int>* score);
int main() {
    vector<string> name(3);
    vector<int> score(3);

    // Calling the function
    getHighScores(&name, &score);

    // Printing the result
    for (int i = 0; i < 3; i++)
    {
        cout << name[i] << endl << score[i] << endl;
    }
}

// Pre: Two empty arrays for names and scores, and a file of datas
// Intent: To find the highest three scores
// Post: Two arrays changed
void getHighScores(vector<string>* name, vector<int>* score) {
    const string FILENAME = "scores.txt";
    string nameTemp;
    int scoreTemp;
    fstream fs;

    // Opening the file
    fs.open(FILENAME);
    
    // Reading the file
    while (fs >> nameTemp >> scoreTemp)
    {
        int i = 0;
        // Finding the index to insert new data
        while (i < 3 && scoreTemp < (*score)[i])
        {
            i++;
        }
        if (i < 3)
        {
            // Inserting the new data
            (*score).insert((*score).begin() + i, scoreTemp);
            (*name).insert((*name).begin() + i, nameTemp);
        }
    }
    // Reducing memory
    (*name).resize(3);
    (*score).resize(3);
    
    // Closing the file
    fs.close();
}