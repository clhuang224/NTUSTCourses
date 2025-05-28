#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
#pragma once
class NumberGame
{
private:
    int input;           // The decimal A.
    string fileName;     // That name of a file that contain the number list S.
    vector<int> digit;   // The digits of A
    vector<int> list;    // The datas in the file
    vector<int> valid;   // The valid values
    int maxProduct;      // The largest product digits of A can make
    bool isValid(int);
    void findValid();
public:
    NumberGame();
    void SetInput(int);         // set input
    void ProcessInput();        // pre-process with your input.
    void SetFileName(string);   // set fileName
    void LoadNumberList();      // Read and pre-process the file
    void PrintAllValid();       // Print all the valid numbers in S ascendingly
    void Reset();               // Reset every state/member.
};