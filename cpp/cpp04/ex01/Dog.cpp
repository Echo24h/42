#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
	std::cout << "Dog default constructor\n";
	this->type = "Dog";
	this->brn = new Brain();
}

Dog::Dog(Dog const & src) {
	std::cout << "Dog copy constructor\n";
}

Dog::~Dog(void) {
	delete (this->brn);
	std::cout << "Dog destructor\n";
}

Dog &	Dog::operator=(Dog const & src) {
	*(this->brn) = *(src.brn);
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Woofwoof!\n";
}

void	Dog::showIdea(int const index) const {
	this->brn->showIdea(index);
}

