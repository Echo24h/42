#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor\n";
}

WrongAnimal::WrongAnimal(std::string const type) {
	std::cout << "WrongAnimal string constructor\n";
	this->type = type;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "WrongAnimal copy constructor\n";
	*this = src;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor\n";
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src) {
	this->type = src.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "'I AM AN AHHHNIMAAAAAL!' (roar a strange WrongAnimal called " << (!this->type.empty() ? this->type : "???") << ")\n";
}

std::string	WrongAnimal::getType(void) const {
	return (this->type);
}
