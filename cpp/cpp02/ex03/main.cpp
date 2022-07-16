#include <iostream>
#include <fstream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed calcTriArea(Point a, Point b, Point c);

int main( void ) {
	Point a(5.0f, 4.5f);
	Point b(4.2f, 0.0f);
	Point c(1.2f, 1.0f);

	Fixed res = calcTriArea(a, b, c);
	std::cout << res << std::endl;
	return 0;
}
