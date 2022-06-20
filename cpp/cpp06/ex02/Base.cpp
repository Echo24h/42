#include "Base.hpp"
#include <iostream>

Base::Base(void) {}

Base::Base(Base const & src) {}

Base::~Base(void) {}

Base & Base::operator=(Base const & src) {
	return (*this);
}
