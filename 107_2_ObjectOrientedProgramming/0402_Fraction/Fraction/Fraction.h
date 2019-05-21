#pragma once
class Fraction
{
public:
	Fraction();
	void setNumerator(long);
	void setDenominator(long);
	void getDouble();
	void outputReducedFraction();
private:
	long numerator;
	long denominator;
};

