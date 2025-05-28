#include "Complex.h"

// Intent: ﹍てComplexン把计箇砞0
// Pre: 0~2double
// Post: ﹍てЧΘ
Complex::Complex(double realPart, double imaginaryPart)
{
    realValue = realPart;
    imaginaryValue = imaginaryPart;
}

// Intent: 眔龟计场だmember function
// Pre: Complexン
// Post: 肚龟计场だ
double Complex::real()
{
    return realValue;
}

// Intent: 眔店计场だmember function
// Pre: Complexン
// Post: 肚店计场だ
double Complex::imag()
{
    return imaginaryValue;
}

// Intent: 眔絛计member function
// Pre: Complexン
// Post: 肚絛计
double Complex::norm()
{
    return sqrt(realValue * realValue + imaginaryValue * imaginaryValue);
}

// Intent: ﹚竡Complexン==
// Pre: Complexン
// Post: 肚龟计の店计琌单
bool Complex::operator == (Complex another)
{
    return (realValue == another.real() && imaginaryValue == another.imag());
}

// Intent: ﹚竡Complexン+
// Pre: Complexン
// Post: 肚挡狦
const Complex operator+ (Complex first, Complex second)
{
    Complex result(first.realValue + second.realValue, first.imaginaryValue + second.imaginaryValue);
    return result;
}

// Intent: ﹚竡Complexン-
// Pre: Complexン
// Post: 肚搭挡狦
const Complex operator- (Complex first, Complex second)
{
    Complex result(first.realValue - second.realValue, first.imaginaryValue - second.imaginaryValue);
    return result;
}

// Intent: ﹚竡Complexン*
// Pre: Complexン
// Post: 肚挡狦
const Complex operator* (Complex first, Complex second)
{
    Complex result(first.realValue * second.realValue - first.imaginaryValue * second.imaginaryValue,
        first.realValue * second.imaginaryValue + first.imaginaryValue * second.realValue);
    return result;
}

// Intent: ﹚竡Complexン/
// Pre: Complexン
// Post: 肚埃挡狦
const Complex operator/ (Complex first, Complex second)
{
    if (second.norm() != 0)
    {
        Complex result((first.realValue * second.realValue + first.imaginaryValue * second.imaginaryValue)
            / (second.realValue * second.realValue + second.imaginaryValue * second.imaginaryValue),
            (first.imaginaryValue * second.realValue - first.realValue * second.imaginaryValue)
            / (second.realValue * second.realValue + second.imaginaryValue * second.imaginaryValue));
        return result;
    }
}

// Intent: ﹚竡Complexン<<
// Pre: Complexン
// Post: 狡计
ostream& operator<< (ostream& outputStream, Complex current)
{
    cout << current.realValue << " + " << current.imaginaryValue << "*i" << endl;
    return outputStream;
}

// Intent: ﹚竡Complexン>>
// Pre: Complexン
// Post: 块把计
istream& operator>> (istream& inputStream, Complex& current)
{
    string temp;
    cin >> temp >> temp >> current.realValue >> temp;
    getline(cin, temp);
    temp = temp.substr(0, temp.length() - 2);
    current.imaginaryValue = stod(temp);
    return inputStream;
}

// Intent: 眔龟计场だglobal function
// Pre: Complexン
// Post: 肚龟计场だ
double real(Complex current)
{
    return current.real();
}

// Intent: 眔店计场だglobal function
// Pre: Complexン
// Post: 肚店计场だ
double imag(Complex current)
{
    return current.imag();
}

// Intent: 眔絛计global function
// Pre: Complexン
// Post: 肚絛计
double norm(Complex current)
{
    return sqrt(current.real() * current.real() + current.imag() * current.imag());
}