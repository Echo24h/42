#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) {
	(void)src;
	std::cout << "WrongCat copy constructor\n";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor\n";
}

WrongCat & WrongCat::operator=(WrongCat const & src) {
	(void)src;
	return (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << "Miaorrruuwwqr! (it sounds terrible)\n";
}
