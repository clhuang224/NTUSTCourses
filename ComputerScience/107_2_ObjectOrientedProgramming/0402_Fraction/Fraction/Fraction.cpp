#include <iostream>
#include "Fraction.h"
#include "gcd.h"

//Intent: 初始化
// Pre: 無
// Post: 初始化
Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}

//Intent: 設定分子數值
// Pre: Fraction物件
// Post: 分子數值被更新
void Fraction::setNumerator(long newNum)
{
	numerator = newNum;
}

//Intent: 設定分母數值
// Pre: Fraction物件
// Post: 分母數值被更新
void Fraction::setDenominator(long newDen)
{
	denominator = newDen;
}

//Intent: 印出分子分母相除double結果
// Pre: Fraction物件
// Post: 結果被印出
void Fraction::getDouble()
{
	std::cout << numerator / static_cast<double>(denominator) << std::endl;
}

//Intent: 印出分子分母相除分數結果
// Pre: Fraction物件
// Post: 結果被印出
void Fraction::outputReducedFraction()
{
	int gcdValue = gcd(numerator, denominator);
	numerator /= gcdValue;
	denominator /= gcdValue;
	std::cout << numerator;
	if (denominator > 1) {
		std::cout << "/" << denominator;
	}
	std::cout << std::endl;
}