#include <iostream>
#include <vector>
using namespace std;
void inputMatrix(vector<vector<double>>&);
vector<vector<double>> multiplyMatrix(vector<vector<double>>, vector<vector<double>>);
void outputMatrix(vector<vector<double>>);

int main() {
    while (!cin.eof())
    {
        unsigned a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<vector<double>> matriceA(b, vector<double>(a)), matriceB(d, vector<double>(c));
        inputMatrix(matriceA);
        inputMatrix(matriceB);
        outputMatrix(multiplyMatrix(matriceA, matriceB));
    }
}

// Intent: 輸入矩陣內容
// Pre: double二維陣列
// Post: 陣列被改變
void inputMatrix(vector<vector<double>>& matrice)
{
    for (unsigned j = 0; j < matrice[0].size(); j++)
    {
        for (unsigned i = 0; i < matrice.size(); i++)
        {
            cin >> matrice[i][j];
        }
    }
}

// Intent: 相乘兩個矩陣
// Pre: 兩個double二維陣列
// Post: 回傳相乘結果
vector<vector<double>> multiplyMatrix(vector<vector<double>> matriceA, vector<vector<double>> matriceB)
{
    if (matriceA.size() == 0 || matriceB.size() == 0 || matriceA.size() != matriceB[0].size())
    {
        cout << "Matrix multiplication failed." << endl;
        return vector<vector<double>>(0);
    }
    else
    {
        vector<vector<double>> result(matriceB.size(), vector<double>(matriceA[0].size(), 0));
        for (unsigned j = 0; j < result[0].size(); j++)
        {
            for (unsigned i = 0; i < result.size(); i++)
            {

                for (unsigned k = 0; k < matriceA.size(); k++)
                {
                   result[i][j] += matriceA[k][j] * matriceB[i][k];
                }

            }
        }
        return result;
    }
}

// Intent: 印出矩陣內容
// Pre: double二維陣列
// Post: 印出陣列
void outputMatrix(vector<vector<double>> matrice)
{
    if (matrice.size() != 0)
    {
        for (unsigned j = 0; j < matrice[0].size(); j++)
        {
            for (unsigned i = 0; i < matrice.size(); i++)
            {
                cout << matrice[i][j] << ((i == matrice.size() - 1) ? "" : " ");
            }
            cout << endl;
        }
    }
}