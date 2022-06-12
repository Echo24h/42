#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string const name) {
	std::cout << "ClapTrap string constructor called\n";
	this->name = name;
	this->pv = 10;
	this->pe = 10;
	this->attackDmg = 0;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap copy constructor called\n";
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & ros) {
	this->name = ros.name;
	this->pv = ros.pv;
	this->pe = ros.pe;
	this->attackDmg = ros.attackDmg;
	return (*this);
}

// --- member functions ---

void	ClapTrap::attack(const std::string & target) {
	if (!this->has_energy() || !this->is_alive())
		return;
	this->pe--;
	std::cout << "ClapTrap " << this->name << " casse la gueule de " << target << ", lui infligeant " << this->attackDmg << " points de dégats\n"; 
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->is_alive())
		return ;
	this->pv -= amount;
	std::cout << "ClapTrap " << this->name << " se fait marave, il perd " << amount << " pv\n"; 
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->has_energy() || !this->is_alive())
		return;
	this->pv += amount;
	this->pe--;
	std::cout << "ClapTrap " << this->name << " prend une taff de sa giga clope magique, il récupère " << amount << " pv\n"; 
}

// --- private member functions ---

bool	ClapTrap::is_alive() {
	return ((this->pv > 0) ? true : false);
}

bool	ClapTrap::has_energy() {
	return ((this->pe > 0) ? true : false);
}
