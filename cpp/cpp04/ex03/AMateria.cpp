#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(AMateria const & src) {
	(void)src;
	*this = src;}

AMateria::~AMateria(void) {}

AMateria & AMateria::operator=(AMateria const & rhs) {
	(void)rhs;
	return (*this);
}

std::string const & AMateria::getType(void) const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
