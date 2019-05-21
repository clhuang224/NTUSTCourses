#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial
{
public:
    Polynomial(double* = {}, unsigned = 0);
    Polynomial(const Polynomial&);
    Polynomial operator=(Polynomial);
    Polynomial operator+(Polynomial) const;
    Polynomial operator-(Polynomial) const;
    Polynomial operator*(Polynomial) const;
    const double& operator [](unsigned) const;

    vector<double> myCoeffient();
    unsigned mySize();
private:
    vector<double> coefficient;
};

double evaluate(Polynomial, double);