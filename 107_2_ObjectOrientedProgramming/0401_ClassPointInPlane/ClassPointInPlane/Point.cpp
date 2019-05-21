#include "Point.h"
#include <iostream>

// Intent: 物件初始化
// Pre: 無
// Post: 物件被初始化
Point::Point(double initialX, double initialY)
{
	x = initialX;
	y = initialY;
}

// Intent: 使用Point物件的x座標
// Pre: Point物件
// Post: 回傳x座標
double Point::RetrieveVertical()
{
	return x;
}

// Intent: 使用Point物件的y座標
// Pre: Point物件
// Post: 回傳y座標
double Point::RetrieveHorizontal()
{
	return y;
}

// Intent: 重設Point物件的座標
// Pre: Point物件
// Post: 座標被更新
void Point::Set(double newX, double newY)
{
	x = newX;
	y = newY;
}

// Intent: 移動Point物件的座標
// Pre: Point物件
// Post: 座標被加上移動量
void Point::Move(double xAmount, double yAmount)
{
	x += xAmount;
	y += yAmount;
}

// Intent: 旋轉Point物件
// Pre: Point物件
// Post: 座標被修改
void Point::Rotate()
{
	std::swap(x, y);
	y *= -1;
}