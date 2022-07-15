#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) {
	std::cout << "Cat default constructor\n";
	this->type = "Cat";
	this->brn = new Brain();
}

Cat::Cat(Cat const & src) {
	std::cout << "Cat copy constructor\n";
	*this = src;
}

Cat::~Cat(void) {
	delete this->brn;
	std::cout << "Cat destructor\n";
}

Cat &	Cat::operator=(Cat const & src) {
	this->brn = new Brain(*src.brn);
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaouuu!\n";
}

void	Cat::showIdea(int const index) const {
	this->brn->showIdea(index);
}
