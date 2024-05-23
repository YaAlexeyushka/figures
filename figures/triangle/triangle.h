#include "../figures.h"
#include "../point/point.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

template <class T>
class Triangle : public Figures {
    T side_1, side_2, side_3;
public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
    Triangle(T p1_x, T p1_y, T p2_x, T p2_y, T p3_x, T p3_y);
    Triangle(T side_1, T side_2, T side_3);

    double calc_area();
    double calc_perimeter();
    string name();
};

template <class T>
Triangle<T>::Triangle() {
    side_1 = 0;
    side_2 = 0;
    side_3 = 0;
};

template <class T>
Triangle<T>::Triangle(Point p1, Point p2, Point p3) {
    side_1 = calcDistance(p1, p2);
    side_2 = calcDistance(p2, p3);
    side_3 = calcDistance(p3, p1);
}

template <class T>
Triangle<T>::Triangle(T p1_x, T p1_y, T p2_x, T p2_y, T p3_x, T p3_y) {
    side_1 = calcDistance(Point(p1_x, p1_y), Point(p2_x, p2_y));
    side_2 = calcDistance(Point(p3_x, p3_y), Point(p2_x, p2_y));
    side_3 = calcDistance(Point(p3_x, p3_y), Point(p1_x, p1_y));
};

template <class T>
Triangle<T>::Triangle(T side_1, T side_2, T side_3) {
    side_1 = side_1;
    side_2 = side_2;
    side_3 = side_3;
}

template <class T>
double Triangle<T>::calc_area() {
    double p2 = (side_1 + side_2 + side_3) / 2.0;

    if (p2 <= 0.0 or p2 <= side_1 or p2 <= side_2 or p2 <= side_3)
        return 0.0;

    return sqrt(p2 * (p2 - side_1) * (p2 - side_2) * (p2 - side_3));
};

template <class T>
double Triangle<T>::calc_perimeter() {
    return side_1 + side_2 + side_3;
};

template <class T>
string Triangle<T>::name() {
    return "Triangle";
};

#endif