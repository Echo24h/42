#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap default constructor called\n";
	this->name = "???";
}

DiamondTrap::DiamondTrap(std::string name) {
	std::cout << "DiamondTrap string constructor called\n";
	this->name = name;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) {
	*this = src;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs) {
	this->name = rhs.name;
	return (*this);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap's name: " << this->DiamondTrap::name << std::endl;
	std::cout << "ClapTrap's name: " << this->ClapTrap::name << std::endl;
}
