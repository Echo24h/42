#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string const name) {
	std::cout << "ScavTrap string constructor called\n";
	this->name = name;
	this->pv = 100;
	this->pe = 50;
	this->attackDmg = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & ros) {
	return (*this);
}

void	ScavTrap::attack(const std::string & target) {
	if (!this->has_energy() || !this->is_alive())
		return;
	this->pe--;
	std::cout << "ScavTrap " << this->name << " détruit " << target << ", lui infligeant " << this->attackDmg << " points de dégats\n"; 
}

void	ScavTrap::guardGate(void) {
	if (!this->is_alive())
		return;
	std::cout << "ScavTrap " << this->name << " s'étire nonchalamment et passe en mode Gate Keeper\n";
}
