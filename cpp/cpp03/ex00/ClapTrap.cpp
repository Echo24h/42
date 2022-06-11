#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_pv(10),
	_pe(10),
	_attackDmg(0) {}

ClapTrap::ClapTrap(ClapTrap const & src) {}

ClapTrap::~ClapTrap(void) {}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {
	return (*this);
}

// --- member functions ---

void	attack(const std::string & target) {
	
}

void	takeDamage(unsigned int amount) {

}

void	beRepaired(unsigned int amount) {

}
