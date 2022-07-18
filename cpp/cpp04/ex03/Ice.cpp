#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) {}

Ice::Ice(Ice const & src) {
	*this = src;
}

Ice::~Ice(void) {}

Ice & Ice::operator=(Ice const & rhs) {
	return (*this);
}
