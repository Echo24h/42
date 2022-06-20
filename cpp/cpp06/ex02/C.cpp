#include "C.hpp"
#include <iostream>

C::C(void) {}

C::C(C const & src) {}

C::~C(void) {}

C & C::operator=(C const & src) {
	return (*this);
}
