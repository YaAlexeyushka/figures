#include <iostream>
#include <vector>
#include "figures/circle/circle.h"
#include "figures/ellipse/ellipse.h"
#include "figures/rectangle/rectangle.h"
#include "figures/triangle/triangle.h"
#include "figures/polygon/polygon.h"
#include "figures/figures.h"
#include <string>

int main() {

	vector<Figures*> figures;
	
	try {
		Circle<int>* ptr_circle = new Circle<int>(144, 12, 2);
		figures.push_back(ptr_circle);

		Triangle<int>* ptr_triangle = new Triangle<int>(1, 2, 5, 8, 9, 10);
		figures.push_back(ptr_triangle);

		Rectangle<int>* ptr_rectangle = new Rectangle<int>(2, 6, 20, 4, 5, 6, 7, 10);
		figures.push_back(ptr_rectangle);

		Point p(2, 4);

		Ellipse<int>* ptr_ellipse = new Ellipse<int>(p, 2, 3);
		figures.push_back(ptr_ellipse);

		vector<int> vect = { 1, 2, 3, 4, 5, 6, 8, 9, 11, 10 };
		Polygon<int>* ptr_polygon = new Polygon<int>(vect);
		figures.push_back(ptr_polygon);
	}
	catch (...){
		cerr << "exception Error!";
	}

	try {
		string file_path = "test.txt";
		Polygon<int>* ptr_polygon2 = new Polygon<int>(file_path);
		figures.push_back(ptr_polygon2);
	}
	catch (...) {
		cerr << "failed to read the file exception";
	}
	
	for (size_t i = 0; i < figures.size(); i++) {
		cout << figures[i]->name() << "'s area is "
			<< figures[i]->calc_area() << ", its perimeter is "
			<< figures[i]->calc_perimeter() << endl;
	}

	return 0;
}