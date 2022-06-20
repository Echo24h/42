#include "B.hpp"
#include <iostream>

B::B(void) {}

B::B(B const & src) {}

B::~B(void) {}

B & B::operator=(B const & src) {
	return (*this);
}
