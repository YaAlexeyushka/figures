#include "../figures.h"
#include "../point/point.h"
#include <string>

#ifndef CIRCLE_H
#define CIRCLE_H

template <class T>
class Circle : public Figures {
	Point center;
	T radius;
	
public:
	Circle(Point _center, T _radius);
	Circle(T center1, T center2, T _radius);

	double calc_area();

	double calc_perimeter();
	string name();

};

template <class T>
Circle<T>::Circle(Point _center, T _radius) {
	center = _center;
	radius = _radius;
}


template <class T>
Circle<T>::Circle(T center1, T center2, T _radius) {
	center.x = center1;
	center.y = center2;
	radius = _radius;
}

template <class T>
double Circle<T>::calc_area() {
	return 3.14 * (radius * radius);
}

template <class T>
double Circle<T>::calc_perimeter() {
	return 2 * 3.14 * radius;
}

template <class T>
string Circle<T>::name() {
	return "Circle";
}

#endif