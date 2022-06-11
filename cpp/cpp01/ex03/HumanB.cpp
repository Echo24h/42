#include "HumanB.hpp"
#include <iostream>

void	HumanB::attack() {
	if (!this->_wp)
		std::cout << this->_name << " doesn't have a weapon\n";
	else
		std::cout << this->_name << " attacks with their " << this->_wp->getType() << std::endl;
};

void	HumanB::setWeapon(Weapon& wp) {
	this->_wp = &wp;
};
