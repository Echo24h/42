#include "C.hpp"
#include <iostream>

C::C(void) {}

C::C(C const & src) {
	*this = src;
}

C::~C(void) {}

C & C::operator=(C const & src) {
	(void)src;
	return (*this);
}
