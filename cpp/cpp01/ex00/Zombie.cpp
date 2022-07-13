#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << this->_name << " is gone... rip :/\n";
}

void Zombie::annouce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
