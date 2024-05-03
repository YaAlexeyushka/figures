#include <iostream>

#ifndef FIGURES_H
#define FIGURES_H

using namespace std;

class Figures {
public:
    virtual double calc_area() = 0;
    virtual double calc_perimeter() = 0;
    virtual void name() = 0;
};

#endif