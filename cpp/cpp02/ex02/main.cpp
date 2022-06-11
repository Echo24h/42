#include <iostream>
#include <fstream>
#include "Fixed.hpp"

int main( void ) {
	std::cout.precision(12);

	Fixed a(-7.0f);
	Fixed b(3.0f);
	a.showRange();
	//std::cout << a << " " << b << " = " << (a / b) << std::endl;
	std::cout << (a * b) << std::endl;
	return 0;
}
