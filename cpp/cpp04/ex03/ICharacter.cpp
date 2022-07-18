#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter(void) {}

ICharacter::ICharacter(ICharacter const & src) {
	*this = src;
}

ICharacter::~ICharacter(void) {}

ICharacter & ICharacter::operator=(ICharacter const & rhs) {
	return (*this);
}
