#include "Polynomial.h"

// Intent: 初始化
// Pre: 宣告Polynomial物件、double陣列、陣列大小
// Post: coefficient初始為double陣列的值
Polynomial::Polynomial(double* value, unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        coefficient.push_back(value[i]);
    }
}
// Intent: 初始化
// Pre: 宣告Polynomial物件、另一個Polynomial物件
// Post: coefficient初始為另一個Polynomial物件的coefficient
Polynomial::Polynomial(const Polynomial& another)
{
    coefficient = another.coefficient;
}

// Intent: 定義Polynomial物件的[]
// Pre: Polynomial物件、index
// Post: 回傳coefficient[index]
const double& Polynomial::operator [](unsigned index)const
{
    return coefficient[index];
}

// Intent: 定義Polynomial物件的=
// Pre: Polynomial物件、另一個Polynomail物件
// Post: 將另一個Polynomial的coefficient assign 給自己的coefficient並回傳自己
Polynomial Polynomial::operator=(Polynomial another)
{
    coefficient = another.myCoeffient();
    return *this;
}

// Intent: 定義Polynomial物件的+
// Pre: 兩個Polynomial物件
// Post: 回傳兩個coeffient相加的Polynomial物件
Polynomial Polynomial::operator+(Polynomial another) const
{
    double* value;
    if (coefficient.size() < another.mySize())
    {
        value = new double[another.mySize()];
        for (unsigned i = 0; i < coefficient.size(); i++)
        {
            value[i] = coefficient[i] + another.myCoeffient()[i];
        }
        for (unsigned i = coefficient.size(); i < another.mySize(); i++)
        {
            value[i] = another.myCoeffient()[i];
        }
        Polynomial result(value, another.mySize());
        delete[]value;
        return result;
    }
    else if (coefficient.size() > another.mySize())
    {
        value = new double[coefficient.size()];
        for (unsigned i = 0; i < another.mySize(); i++)
        {
            value[i] = coefficient[i] + another.myCoeffient()[i];
        }
        Polynomial result(value, another.mySize());
        delete[]value;
        return result;
    }
    else
    {
        value = new double[another.mySize()];
        for (unsigned i = 0; i < coefficient.size(); i++)
        {
            value[i] = coefficient[i] + another.myCoeffient()[i];
        }
        Polynomial result(value, another.mySize());
        delete[]value;
        return result;
    }

}

// Intent: 定義Polynomial物件的-
// Pre: 兩個Polynomial物件
// Post: 回傳兩個coeffient相減的Polynomial物件
Polynomial Polynomial::operator-(Polynomial another)const
{
    double* value;
    if (coefficient.size() < another.mySize())
    {
        value = new double[another.mySize()];
        for (unsigned i = 0; i < coefficient.size(); i++)
        {
            value[i] = coefficient[i] - another.myCoeffient()[i];
        }
        for (unsigned i = coefficient.size(); i < another.mySize(); i++)
        {
            value[i] = 0 - another.myCoeffient()[i];
        }
        Polynomial result(value, another.mySize());
        delete[]value;
        return result;
    }
    else if (coefficient.size() > another.mySize())
    {
        value = new double[coefficient.size()];
        for (unsigned i = 0; i < another.mySize(); i++)
        {
            value[i] = coefficient[i] - another.myCoeffient()[i];
        }
        Polynomial result(value, another.mySize());
        delete[]value;
        return result;
    }
    else
    {
        value = new double[another.mySize()];
        for (unsigned i = 0; i < coefficient.size(); i++)
        {
            value[i] = coefficient[i] - another.myCoeffient()[i];
        }
        Polynomial result(value, another.mySize());
        delete[]value;
        return result;
    }
}

// Intent: 定義Polynomial物件的*
// Pre: 兩個Polynomial物件
// Post: 回傳兩個coeffient相乘的Polynomial物件
Polynomial Polynomial::operator*(Polynomial another)const
{
    double* value;
    value = new double[coefficient.size() + another.mySize() - 1];
    for (unsigned i = 0; i < coefficient.size() + another.mySize() - 1; i++)
    {
        value[i] = 0;
    }
    for (unsigned i = 0; i < coefficient.size(); i++)
    {
        for (unsigned j = 0; j < another.mySize(); j++)
        {
            value[i + j] += coefficient[i] * another.myCoeffient()[j];
        }
    }
    Polynomial result(value, coefficient.size() + another.mySize() - 1);
    delete[]value;
    return result;
}

// Intent: 取得Polynomial物件的coefficient
// Pre: Polynomial物件
// Post: 回傳coefficient
vector<double> Polynomial::myCoeffient()
{
    return coefficient;
}

// Intent: 取得Polynomial物件的coefficient.size()
// Pre: Polynomial物件
// Post: 回傳coefficient.size()
unsigned Polynomial::mySize()
{
    return coefficient.size();
}

// Intent: 計算f(x)=c0+c1X+...+cnX^n
// Pre: Polynomial物件、x值
// Post: 回傳f(x)
double evaluate(Polynomial f, double x)
{
    double result = 0;
    for (unsigned i = 0; i < f.mySize(); i++)
    {
        result += f[i] * pow(x, i);
    }
    return result;
}

