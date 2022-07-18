#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) {}

Cure::Cure(Cure const & src) {
	*this = src;
}

Cure::~Cure(void) {}

Cure & Cure::operator=(Cure const & rhs) {
	return (*this);
}
