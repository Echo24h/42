#include <iostream>
#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(Cure const & src) : AMateria("cure") {
	*this = src;
}

Cure::~Cure(void) {}

Cure & Cure::operator=(Cure const & rhs) {
	(void)rhs;
	return (*this);
}

AMateria * Cure::clone(void) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
