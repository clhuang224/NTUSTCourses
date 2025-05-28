#include "NumberGame.h"

// Intent: 初始化
// Pre: 宣告NumberGame物件
// Post: 初始化完成
NumberGame::NumberGame()
{
    input = 0;
    fileName = "";
    digit = {};
    valid = {};
    list = {};
    maxProduct = 1;
}

// Intent: 修改input
// Pre: 新的input
// Post: input被更新
void NumberGame::SetInput(int newInput)
{
    input = newInput;
}

// Intent: 將input的數字分別存進digit陣列
// Pre: NumberGame物件
// Post: digit陣列被更新
void NumberGame::ProcessInput()
{
    int current = input;
    for (unsigned i = 0; current != 0; i++)
    {
        int newDigit = current % 10;
        current /= 10;
        unsigned j = 0;
        while (j < digit.size() && newDigit > digit[j])
        {
            j++;
        }
        digit.insert(digit.begin() + j, newDigit);
        if (newDigit != 0)
        {
            maxProduct *= newDigit;
        }
    }
}

// Intent: 修改fileName
// Pre: 新的fileName
// Post: fileName被更新
void NumberGame::SetFileName(string newFileName)
{
    fileName = newFileName;
}

// Intent: 將檔案中的資料讀取到list陣列中
// Pre: NumberGame物件
// Post: list被更新
void NumberGame::LoadNumberList()
{
    fstream file;
    file.open(fileName);
    if (file.is_open())
    {
        int data;
        while (file >> data)
        {
            int j = list.size() - 1;
            while (j >= 0 && data < list[j])
            {
                j--;
            }
            j++;
            list.insert(list.begin() + j, data);
        }
        file.close();
    }
}

// Intent: 找到所有valid並印出
// Pre: NumberGame物件
// Post: 印出valid的數值
void NumberGame::PrintAllValid()
{
    findValid();
    for (unsigned i = 0; i < valid.size(); i++)
    {
        cout << valid[i] << endl;
    }
}

// Intent: 重設物件內容
// Pre: NumberGame物件
// Post: 重設為初始的狀態
void NumberGame::Reset()
{
    input = 0;
    fileName = "";
    digit.clear();
    list.clear();
    valid.clear();
    maxProduct = 1;
}

// Intent: 將list中valid的值存入valid陣列中
// Pre: NumberGame物件
// Post: valid陣列被更新
void NumberGame::findValid()
{
    if (valid.empty() == false)
    {
        valid.clear();
    }
    for (unsigned i = 0; i < list.size(); i++)
    {
        if (isValid(list[i]) == true)
        {
            unsigned j = 0;
            while (j < valid.size() && list[i] > valid[j])
            {
                j++;
            }
            valid.insert(valid.begin() + j, list[i]);
        }
    }
}

// Intent: 分辨特定的值是否valid
// Pre: NumberGame物件
// Post: 回傳真假值
bool NumberGame::isValid(int data)
{
    if (data == 0) // data 為 0 的情況
    {
        for (int d : digit)
        {
            if (d == 0)
            {
                return true;
            }
        }
        return false;
    }
    else if (data == 1) // data 為 1 的情況
    {
        for (int d : digit)
        {
            if (d == 1)
            {
                return true;
            }
        }
        return false;
    }
    else if (data > maxProduct) // data若大於總乘積則not valid
    {
        return false;
    }
    else // 利用因數關係找出是否valid
    {
        int product = 1;
        for (unsigned i = 0; i < digit.size(); i++)
        {
            if (data % digit[i] == 0)
            {
                product *= digit[i];
            }
        }
        if (product % data == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}