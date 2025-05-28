#include <iostream>
#include <fstream>
using namespace std;
// Intent: 複製檔案
// Pre: 兩個檔名
// Post: 複製完成
int main(int amount, char** fileName)
{
    if (amount == 3)
    {
        ifstream fileInput(fileName[1], ios::binary);
        ofstream fileOutput(fileName[2], ios::binary);
        if (fileInput.is_open() && fileOutput.is_open())
        {
            while (fileInput.eof() == false)
            {
                fileOutput.put(fileInput.get());
            }
            fileInput.close();
            fileOutput.close();
        }
    }

}