#include "HumanA.hpp"
#include <iostream>

void	HumanA::attack() {
	std::cout << this->_name << " attacks with their " << this->_wp.getType() << std::endl;
};

void	HumanA::setWeapon(Weapon& wp) {
	this->_wp = wp;
};

