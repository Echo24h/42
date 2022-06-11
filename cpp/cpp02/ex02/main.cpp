#include <iostream>
#include <fstream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed c(38);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, c ) << std::endl;
	return 0;
}
