#include "Base.hpp"
#include <iostream>

Base::Base(void) {}

Base::Base(Base const & src) {
	*this = src;
}

Base::~Base(void) {}

Base & Base::operator=(Base const & src) {
	(void)src;
	return (*this);
}
