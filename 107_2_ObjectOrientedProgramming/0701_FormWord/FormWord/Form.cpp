#include "Form.h"

// Intent: 初始化Form物件
// Pre: 宣告Form物件
// Post: input及fileName初始為空字串、result初始為空陣列
Form::Form()
{
    input = "";
    fileName = "";
    result = {};
}

// Intent: 設定input
// Pre: inputWord參數
// Post: input設定為inputWord
void Form::SetInputWord(string inputWord)
{
    input = inputWord;
}

// Intent: 將input字串改為小寫
// Pre: Form物件
// Post: input更新
void Form::ProcessInputWord()
{
    for (unsigned i = 0; i < input.length(); i++)
    {
        if (input[i] >= 65 && input[i] <= 90)
        {
            input[i] += 32;
        }
    }
}

// Intent: 設定fileName
// Pre: newFileName參數
// Post: fileNmae設定為newFileName
void Form::SetFileName(string newFileName)
{
    fileName = newFileName;
}

// Intent: 讀取並比對文字
// Pre: Form物件
// Post: result更新
void Form::Load_CompaerWord()
{
    // 清除result
    result = {};

    // 開啟檔案
    fstream file;
    file.open(fileName);

    // 讀取字詞
    string current = "";
    while (file >> current)
    {
        string compare = input;
        bool read = true;
        if (current.length() > compare.length())
        {
            read = false;
        }
        else
        {
            for (unsigned i = 0; i < current.length() && read == true; i++)
            {
                bool match = false;
                for (unsigned j = 0; j < compare.length() && match == false; j++)
                {
                    if (current[i] == compare[j])
                    {
                        match = true;
                        compare.erase(j,1);
                        j--;
                    }
                }
                if (match == false)
                {
                    read = false;
                }
            }
        }
        if (read == true)
        {
            result.push_back(current);
        }
        compare = input;
    }


    // 關閉檔案
    file.close();
}

// Intent: 印出結果
// Pre: Form物件
// Post: 印出結果
void Form::PrintFoundWords()
{
    for (string item : result)
    {
        cout << item << endl;
    }
}