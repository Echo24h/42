#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
	std::cout << "Animal default constructor\n";
}

Animal::Animal(std::string const type) {
	std::cout << "Animal string constructor\n";
	this->type = type;
}

Animal::Animal(Animal const & src) {
	std::cout << "Animal copy constructor\n";
	*this = src;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor\n";
}

Animal &	Animal::operator=(Animal const & src) {
	this->type = src.type;
	return (*this);
}

std::string	Animal::getType(void) const {
	return (this->type);
}
