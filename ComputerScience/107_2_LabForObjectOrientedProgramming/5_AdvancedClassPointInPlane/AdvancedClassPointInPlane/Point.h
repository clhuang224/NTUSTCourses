#include<iostream>
#pragma once
using namespace std;
class Point
{
public:
    Point(float = 0, float = 0);
    ~Point();
    void Set(float = 0, float = 0);
    void Move(float = 0, float = 0);
    void Rotate();
    void Reflect();
    float RetrieveHorizontal();
    float RetrieveVertical();
    void operator = (const Point&) const;
private:
    float *point;
};

