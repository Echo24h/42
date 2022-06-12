#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) {
	std::cout << "WrongCat copy constructor\n";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor\n";
}

WrongCat &	WrongCat::operator=(WrongCat const & src) {
	return (*this);
}
