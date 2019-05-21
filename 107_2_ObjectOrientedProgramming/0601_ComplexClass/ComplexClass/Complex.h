#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Complex
{
public:
    Complex(double = 0, double = 0);
    double real();
    double imag();
    double norm();
    bool operator == (Complex);
    friend const Complex operator+ (Complex, Complex);
    friend const Complex operator- (Complex, Complex);
    friend const Complex operator* (Complex, Complex);
    friend const Complex operator/ (Complex, Complex);
    friend ostream& operator<< (ostream&, Complex);
    friend istream& operator>> (istream&, Complex&);
private:
    double realValue;
    double imaginaryValue;
};

double real(Complex);
double imag(Complex);
double norm(Complex);