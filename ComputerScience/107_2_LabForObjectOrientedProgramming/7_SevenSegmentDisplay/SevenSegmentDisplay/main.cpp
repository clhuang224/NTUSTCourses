#include <iostream>
#include <string>
using namespace std;
void printBySevenSegment(string);
int main() {
    string input;
    while (!cin.eof())
    {
        // 輸入整行
        getline(cin,input);
        // 輸出結果
        printBySevenSegment(input);
    }
}

// Intent: 將字串中的數字以SevenSegment的格式印出
// Pre: 字串
// Post: 印出結果
void printBySevenSegment(string input)
{
    // 宣告上中下三個字串
    string top, middle, bottom;
    // 依據每個字元，將數字的格式依序放入上中下字串，非數字則忽略
    for (unsigned i = 0; i < input.length(); i++)
    {
        switch (input[i])
        {
        case '0':
            top.append(" _ ");
            middle.append("| |");
            bottom.append("|_|");
            break;
        case '1':
            top.append("   ");
            middle.append("  |");
            bottom.append("  |");
            break;
        case '2':
            top.append(" _ ");
            middle.append(" _|");
            bottom.append("|_ ");
            break;
        case '3':
            top.append(" _ ");
            middle.append(" _|");
            bottom.append(" _|");
            break;
        case '4':
            top.append("   ");
            middle.append("|_|");
            bottom.append("  |");
            break;
        case '5':
            top.append(" _ ");
            middle.append("|_ ");
            bottom.append(" _|");
            break;
        case '6':
            top.append(" _ ");
            middle.append("|_ ");
            bottom.append("|_|");
            break;
        case '7':
            top.append(" _ ");
            middle.append("  |");
            bottom.append("  |");
            break;
        case '8':
            top.append(" _ ");
            middle.append("|_|");
            bottom.append("|_|");
            break;
        case '9':
            top.append(" _ ");
            middle.append("|_|");
            bottom.append(" _|");
            break;

        }
    }
    // 印出結果
    cout << top << endl << middle << endl << bottom << endl;

}