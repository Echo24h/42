#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp" 

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;

	ScavTrap	p1("yo");
	p1.attack("lol");
	p1.guardGate();
	
	std::cout << std::endl;
	ScavTrap p2("xxx");
	for (int i = 0; i < 55; i++) {
		p2.attack("target");
	}

	return (0);
}
