#include "A.hpp"
#include <iostream>

A::A(void) {}

A::A(A const & src) {}

A::~A(void) {}

A & A::operator=(A const & src) {
	return (*this);
}
