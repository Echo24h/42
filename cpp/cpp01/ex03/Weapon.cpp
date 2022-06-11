#include "Weapon.hpp"
#include <iostream>

std::string&	Weapon::getType() {
	return (this->_type);
};

void			Weapon::setType(std::string newType) {
	this->_type = newType;
};
