#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain default constructor\n";
	this->ideas[0] = "salope";
}

Brain::Brain(Brain const & src) {
	std::cout << "Brain copy constructor\n";
	*this = src;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor\n";
}

Brain &	Brain::operator=(Brain const & src) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

void	Brain::showIdea(int const index) const {
	if (index < 0 || index >= 100)
		return;
	std::cout << this->ideas[index] << std::endl;
}

void	Brain::addIdea(std::string const idea) {
	static int index = 1;

	if (index == 100) {
		index = 0;
	}
	this->ideas[index++] = idea;
}