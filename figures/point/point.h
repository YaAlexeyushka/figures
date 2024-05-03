#include <iostream>

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point {
public:
	double x, y;
	Point();
	Point(double xx, double yy);
};

double calcDistance(const Point& pp1, const Point& pp2);

#endif