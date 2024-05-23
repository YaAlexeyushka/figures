#include "../figures.h"
#include "../point/point.h"

#ifndef EllIPSE_H
#define ELLIPSE_H

template <class T>
class Ellipse : public Figures {
	Point center;
	T radius1;
	T radius2;

public:
	Ellipse(Point _center, T _radius1, T _radius2);
	Ellipse(T center1, T center2, T _radius1, T _radius2);

	double calc_area();

	double calc_perimeter();
	string name();

};

template <class T>
Ellipse<T>::Ellipse(Point _center, T _radius1, T _radius2) {
	center = _center;
	radius1 = _radius1;
	radius2 = _radius2;
}


template <class T>
Ellipse<T>::Ellipse(T center1, T center2, T _radius1, T _radius2) {
	center.x = center1;
	center.y = center2;
	radius1 = _radius1;
	radius2 = _radius2;
}

template <class T>
double Ellipse<T>::calc_area() {
	return 3.14 * (radius1 * radius2);
}

template <class T>
double Ellipse<T>::calc_perimeter() {
	return 2 * 3.14 * sqrt((radius1 * radius1 + radius2 * radius2) / 2);
}

template <class T>
string Ellipse<T>::name() {
	return "Ellipse";
}
#endif