#include "Zombie.hpp"

Zombie::Zombie(void) {
	this->_name = "anonyme";
}

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::~Zombie() {
	std::cout << _name << " is gone... rip :/\n";
}

void Zombie::annouce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
