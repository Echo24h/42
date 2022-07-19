#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = nullptr;
	}
}

Character::Character(Character const & src) {
	*this = src;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		delete this->_inventory[i];
	}
}

Character & Character::operator=(Character const & rhs) {
	for (int i = 0; i < 4; i++) {
		delete this->_inventory[i];
	}

	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName(void) const {
	return (this->_name);
}

void Character::equip(AMateria * m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == nullptr) {
			this->_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (this->_inventory[idx] != nullptr) {
		this->_inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter & target) {
	if (this->_inventory[idx] != nullptr) {
		this->_inventory[idx]->use(target);
	}
}
