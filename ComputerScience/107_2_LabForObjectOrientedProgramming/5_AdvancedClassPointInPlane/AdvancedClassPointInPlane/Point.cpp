#include "Point.h"

const unsigned int X = 0, Y = 1;

//Intent: 初始化
//Pre: 宣告Point物件
//Post: 初始化為參數或預設值
Point::Point(float x, float y)
{
    point = new float[2];
    point[X] = x;
    point[Y] = y;
}

//Intent: 更改座標
//Pre: Point物件
//Post: 更改座標為參數或預設值
void Point::Set(float x, float y)
{
    point[X] = x;
    point[Y] = y;
}

//Intent: 移動座標
//Pre: Point物件
//Post: 座標更新
void Point::Move(float x, float y)
{
    point[X] += x;
    point[Y] += y;
}

//Intent: 旋轉座標90度
//Pre: Point物件
//Post: 座標更新
void Point::Rotate()
{
    swap(point[X], point[Y]);
    point[Y] = 0 - point[Y];
}

//Intent: 以原點投影座標
//Pre: Point物件
//Post: 座標更新
void Point::Reflect()
{
    point[X] = 0 - point[X];
    point[Y] = 0 - point[Y];
}

//Intent: 找出X座標
//Pre: Point物件
//Post: 回傳X座標
float Point::RetrieveHorizontal()
{
    return point[X];
}

//Intent: 找出Y座標
//Pre: Point物件
//Post: 回傳Y座標
float Point::RetrieveVertical()
{
    return point[Y];
}

//Intent: 定義Point物件間 = 的意義
//Pre: Point物件
//Post: asign 對應數值
void Point::operator = (const Point& another) const
{
    point[X] = another.point[X];
    point[Y] = another.point[Y];
}

//Intent: 解構式
//Pre: 無
//Post: 釋放記憶體
Point::~Point()
{
    delete [] point;
}