#include "VecNf.h"

// Intent: 初始化
// Pre: 宣告VecNf物件
// Post: data初始為{NULL}
VecNf::VecNf()
{
    data = {NULL};
}

// Intent: 初始化
// Pre: 宣告VecNf物件，float*和unsigned參數
// Post: data初始為size大小，並放入values
VecNf::VecNf(float* values, unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        data[i] = values[i];
    }
}

// Intent: 取得陣列大小
// Pre: VecNf物件
// Post: 回傳陣列大小
unsigned VecNf::Size()
{
    return data.size();
}

// Intent: 定義VecNf物件的=
// Pre: VecNf物件
// Post: Asign並印出ASSIGNMENT!!!
void VecNf::operator=(VecNf another)
{
    data = another.data;
    cout << "ASSIGNMENT!!!" << endl;
}

// Intent: 定義VecNf物件的[]
// Pre: VecNf物件、index參數
// Post: 回傳對應的element
float& VecNf::operator[](unsigned index)
{
    return data[index];
}

// Intent: 定義VecNf物件的+
// Pre: 兩個VecNf物件
// Post: 回傳相加結果
VecNf VecNf::operator+(VecNf another)
{
    if (data.size() != another.Size())
    {
        cout << "dimensions inconsistent" << endl;
        return VecNf();
    }
    float* temp = new float[data.size()];
    for (unsigned i = 0; i < data.size(); i++)
    {
        temp[i] = data[i] + another[i];
    }
    VecNf result(temp, data.size());
    delete [] temp;
    return result;
}

// Intent: 定義VecNf物件的-
// Pre: 兩個VecNf物件
// Post: 回傳相減結果
VecNf VecNf::operator-(VecNf another)
{
    if (data.size() != another.Size())
    {
        cout << "dimensions inconsistent" << endl;
        return VecNf();
    }
    float* temp = new float[data.size()];
    for (unsigned i = 0; i < data.size(); i++)
    {
        temp[i] = data[i]- another[i];
    }
    VecNf result(temp, data.size());
    delete[] temp;
    return result;
}

// Intent: 定義兩個VecNf物件間的*
// Pre: 兩個VecNf物件
// Post: 回傳內積結果
float VecNf::operator*(VecNf another)
{
    if (data.size() != another.Size())
    {
        cout << "dimensions inconsistent" << endl;
        return 0;
    }
    float result = 0;
    for (unsigned i = 0; i < data.size(); i++)
    {
        result += data[i] * another[i];
    }
    return result;
}

// Intent: 定義VecNf * 純量
// Pre: VecNf物件及純量參數
// Post: data更新
VecNf VecNf::operator*(float scale)
{
    float* temp = new float[data.size()];
    for (unsigned i = 0; i < data.size(); i++)
    {
        temp[i] = data[i] * scale;
    }
    VecNf result(temp, data.size());
    delete[] temp;
    return result;
}

// Intent: 定義純量 * VecNf
// Pre: float 及 VecNf物件
// Post: data更新
VecNf operator*(VecNf vector, float scale)
{
    float* temp = new float[vector.Size()];
    for (unsigned i = 0; i < vector.Size(); i++)
    {
        temp[i] = vector[i] * scale;
    }
    VecNf result(temp, vector.Size());
    delete[] temp;
    return result;
}