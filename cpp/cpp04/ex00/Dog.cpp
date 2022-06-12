#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
	std::cout << "Dog default constructor\n";
	this->type = "Dog";
}

Dog::Dog(Dog const & src) {
	std::cout << "Dog copy constructor\n";
}

Dog::~Dog(void) {
	std::cout << "Dog destructor\n";
}

Dog &	Dog::operator=(Dog const & src) {
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Woofwoof!\n";
}
