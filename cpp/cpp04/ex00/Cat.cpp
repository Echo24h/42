#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) {
	std::cout << "Cat default constructor\n";
	this->type = "Cat";
}

Cat::Cat(Cat const & src) {
	std::cout << "Cat copy constructor\n";
}

Cat::~Cat(void) {
	std::cout << "Cat destructor\n";
}

Cat &	Cat::operator=(Cat const & src) {
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaouuu!\n";
}
