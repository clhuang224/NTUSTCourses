#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Intent: 找出字詞列表中最長的相反詞
// Pre: 字詞列表.txt
// Post: 印出結果
int main() {

    fstream file;
    // list[字串長度][字首][字尾][index] = 字串
    vector<vector<vector<vector<string>>>> list(1, vector<vector<vector<string>>>(26, vector<vector<string>>(26)));

    // 讀檔
    file.open("words.txt");
    if (file.fail() != true)
    {
        // 讀詞
        string current;
        while (file >> current)
        {
            bool isString = true;
            for (unsigned i = 0; i < current.length(); i++)
            {
                if ('A' <= current[i] && current[i] <= 'Z')
                {
                    current[i] += 32;
                }
                if (current[i] <'A' || current[i] >'z')
                {
                    isString = false;
                }
            }

            // 存入陣列
            if (isString == true)
            {
                if (current.length()+1 > list.size())
                {
                    list.resize(current.length() + 1, vector<vector<vector<string>>>(26, vector<vector<string>>(26)));
                }
                list[static_cast<unsigned>(current.length())][static_cast<unsigned>(current[0] - 'a')]
                    [static_cast<unsigned>(current[current.length() - 1] - 'a')]
                    .push_back(current);
            }
        }
    }
    // 關檔
    file.close();

    // 找出結果
    string reversal = "", result;
    for (vector<vector<vector<string>>> sublistByLength : list)
    {
        for (vector<vector<string>> sublistByHead : sublistByLength)
        {
            for (vector<string> sublistByTail : sublistByHead)
            {
                for (unsigned i = 0; i < sublistByTail.size(); i++)
                {
                    reversal = "";
                    for (unsigned j = 0; j < sublistByTail[i].length(); j++)
                    {
                        reversal.insert(0, 1, sublistByTail[i][j]);
                    }
                    for (unsigned j = 0; list[reversal.length()].empty() == false &&
                                         list[reversal.length()][static_cast<unsigned>(reversal[0] - 'a')].empty() == false &&
                                         j < list[reversal.length()]
                                                 [static_cast<unsigned>(reversal[0] - 'a')]
                                                 [static_cast<unsigned>(reversal[reversal.length() - 1] - 'a')].size(); j++)
                    {
                        if (reversal != sublistByTail[i] &&
                            reversal.length() > result.length() &&
                            (reversal == list[reversal.length()]
                                             [static_cast<unsigned>(reversal[0] - 'a')]
                                             [static_cast<unsigned>(reversal[reversal.length() - 1] - 'a')]
                                             [j]))
                        {
                            result = sublistByTail[i];
                        }
                    }
                }
            }
        }
        

    }

    // 印出結果
    cout << result << endl;

    system("pause");
}