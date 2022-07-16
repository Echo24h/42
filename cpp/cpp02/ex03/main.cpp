#include <iostream>
#include <fstream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(0.0f, 0.0f);
	Point b(1, 3);
	Point c(2, 0);

	Point p(0.5f, 0.5f); // in
	Point p1(1, 1); // in
	Point p2(2.0f, 0.1f); // out
	Point p3(2.01f, 0.0f); // out
	Point p4(2.0f, 0.0f); // in
	
	std::cout << bsp(a, b, c, p3) << std::endl;
	return 0;
}
