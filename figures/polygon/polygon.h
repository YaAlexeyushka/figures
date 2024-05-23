#include "../figures.h"
#include "../point/point.h"
#include <vector>
#include <string>
#include <fstream>

#ifndef POLYGON_H
#define POLYGON_H

template <class T>
class Polygon : public Figures {
    vector<Point> vertices;

public:
    Polygon();
    Polygon(vector<Point> _vertices);
    Polygon(vector<T> _vertices);
    Polygon(string file);

    double calc_area();
    double calc_perimeter();
    string name();
};

template <class T>
Polygon<T>::Polygon() {};

template <class T>
Polygon<T>::Polygon(vector<Point> _vertices) {
    vertices = _vertices;
};

template <class T>
Polygon<T>::Polygon(vector<T> _vertices) {
    if (_vertices.size() % 2 != 0) {
        throw "incorrect size exception";
    }
    for (size_t i = 0; i < _vertices.size(); i += 2) {
        vertices.push_back(Point(_vertices[i], _vertices[i + 1]));
    }
}

template <class T>
Polygon<T>::Polygon(string path) {
    T x, y;

    ifstream file(path);
    if (file.is_open()) {
        int n;
        file >> n;

        for (int i = 0; i < n; i++) {
            file >> x >> y;
            vertices.push_back(Point(x, y));
        }
    }
    else {
        throw "could not open the file exception";
    }
}

template <class T>
double Polygon<T>::calc_area() {
    size_t size = vertices.size();
    double area = 0;

    for (size_t i = 0; i < size-1; ++i) {
        area += (vertices[i].x * vertices[(i + 1)].y) - (vertices[(i + 1)].x * vertices[i].y);
    }
    area += (vertices[size - 1].x * vertices[0].y) - (vertices[0].x * vertices[size - 1].y);

    return abs(area) / 2;
}

template <class T>
double Polygon<T>::calc_perimeter() {
    double perimeter = 0;
    size_t size = vertices.size();
    for (size_t i = 0; i < size-1; ++i) {
        perimeter += calcDistance(vertices[i], vertices[(i + 1)]);
    }
    perimeter += calcDistance(vertices[size - 1], vertices[0]);

    return perimeter;
}

template <class T>
string Polygon<T>::name() {
    return "Polygon";
};

#endif