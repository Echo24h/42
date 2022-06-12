#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) {
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string const name) {
	std::cout << "FragTrap string constructor called\n";
	this->name = name;
	this->pv = 100;
	this->pe = 100;
	this->attackDmg = 30;
}

FragTrap::FragTrap(FragTrap const & src) {
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called\n";
}

FragTrap &	FragTrap::operator=(FragTrap const & ros) {
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	if (!this->is_alive())
		return;
	std::cout << "FragTrap " << this->name << " propose un high five\n";
}
