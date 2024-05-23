#include "../figures.h"
#include "../point/point.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

template <class T>
class Rectangle : public Figures {
    T side_1, side_2;
public:
    Rectangle();
    Rectangle(Point p1, Point p2, Point p3, Point p4);
    Rectangle(T p1_x, T p1_y, T p2_x, T p2_y, T p3_x, T p3_y, T p4_x, T p4_y);
    Rectangle(T side_1, T side_2);
    double calc_area();
    double calc_perimeter();
    string name();
};


template <class T>
Rectangle<T>::Rectangle() {
    side_1 = 0;
    side_2 = 0;
};

template <class T>
Rectangle<T>::Rectangle(Point p1, Point p2, Point p3, Point p4) {
    side_1 = calcDistance(p1, p2);
    side_2 = calcDistance(p3, p4);
}

template <class T>
Rectangle<T>::Rectangle(T p1_x, T p1_y, T p2_x, T p2_y, T p3_x, T p3_y, T p4_x, T p4_y) {
    side_1 = calcDistance(Point(p1_x, p1_y), Point(p2_x, p2_y));
    side_2 = calcDistance(Point(p3_x, p3_y), Point(p4_x, p4_y));
};

template <class T>
Rectangle<T>::Rectangle(T side_1, T side_2) {
    side_1 = side_1;
    side_2 = side_2;
}

template <class T>
double Rectangle<T>::calc_area() {
    return side_1 * side_2;
};

template <class T>
double Rectangle<T>::calc_perimeter() {
    return 2 * (side_1 + side_2);
};

template <class T>
string Rectangle<T>::name() {
    return "Rectangle";
};

#endif