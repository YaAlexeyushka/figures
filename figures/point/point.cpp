#include "point.h"
#include <iostream>

using namespace std;

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double xx, double yy) {
	x = xx;
	y = yy;
}

double calcDistance(const Point& pp1, const Point& pp2) {
	return sqrt((pp2.x - pp1.x) * (pp2.x - pp1.x) + (pp2.y - pp1.y) * (pp2.y - pp1.y));
}