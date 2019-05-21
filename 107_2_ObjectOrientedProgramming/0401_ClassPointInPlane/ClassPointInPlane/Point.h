#pragma once
class Point
{
public:
	Point(double = 0, double = 0);
	double RetrieveVertical();
	double RetrieveHorizontal();
	void Set(double, double);
	void Move(double, double);
	void Rotate();
private:
	double x;
	double y;
};

