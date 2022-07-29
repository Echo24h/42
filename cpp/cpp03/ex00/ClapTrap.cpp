#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) {
	std::cout << "constructor called\n";
	this->_name = name;
	this->_pv = 10;
	this->_pe = 10;
	this->_attackDmg = 0;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "copy constructor called\n";
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "destructor called\n";
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & ros) {
	this->_name = ros._name;
	this->_pv = ros._pv;
	this->_pe = ros._pe;
	this->_attackDmg = ros._attackDmg;
	return (*this);
}

// --- member functions ---

void	ClapTrap::attack(const std::string & target) {
	if (!this->has_energy() || !this->is_alive())
		return;
	this->_pe--;
	std::cout << "ClapTrap " << this->_name << " casse la gueule de " << target << ", lui infligeant " << this->_attackDmg << " points de dégats\n"; 
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->is_alive())
		return ;
	this->_pv -= amount;
	std::cout << "ClapTrap " << this->_name << " se fait marave, il perd " << amount << " pv\n"; 
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->has_energy() || !this->is_alive())
		return;
	this->_pv += amount;
	this->_pe--;
	std::cout << "ClapTrap " << this->_name << " prend une taff de sa giga clope magique, il récupère " << amount << " pv\n"; 
}

// --- private member functions ---

bool	ClapTrap::is_alive() {
	return ((this->_pv > 0) ? true : false);
}

bool	ClapTrap::has_energy() {
	return ((this->_pe > 0) ? true : false);
}
