#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
	_name = name;
	_wp = nullptr;
}

HumanB::HumanB(std::string name, Weapon & wp) {
	_name = name;
	_wp = &wp;
}

void	HumanB::attack(void) {
	if (!this->_wp)
		std::cout << this->_name << " doesn't have a weapon\n";
	else
		std::cout << this->_name << " attacks with their " << this->_wp->getType() << std::endl;
};

void	HumanB::setWeapon(Weapon& wp) {
	this->_wp = &wp;
};
