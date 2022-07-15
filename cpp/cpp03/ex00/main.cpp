#include <iostream>
#include "ClapTrap.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;

	ClapTrap p1("john");

	p1.attack("random");
	p1.takeDamage(5);
	p1.attack("zorglube");
	p1.beRepaired(5);
	p1.attack("new zorglube");

	std::cout << std::endl;
	ClapTrap p2("xxx");
	for (int i = 0; i < 15; i++) {
		p2.attack("target");
	}
	return (0);
}
