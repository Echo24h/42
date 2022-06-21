#include "B.hpp"
#include <iostream>

B::B(void) {}

B::B(B const & src) {
	*this = src;
}

B::~B(void) {}

B & B::operator=(B const & src) {
	(void)src;
	return (*this);
}
