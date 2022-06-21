#include "A.hpp"
#include <iostream>

A::A(void) {}

A::A(A const & src) {
	*this = src;
}

A::~A(void) {}

A & A::operator=(A const & src) {
	(void)src;
	return (*this);
}
