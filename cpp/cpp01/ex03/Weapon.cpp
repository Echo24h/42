#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void) {
	this->_type = "";
}

Weapon::Weapon(std::string type) {
	this->_type = type;
}

std::string const & Weapon::getType(void) const {
	return (this->_type);
};

void Weapon::setType(std::string newType) {
	this->_type = newType;
};
