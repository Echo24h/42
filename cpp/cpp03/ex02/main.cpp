#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp" 
#include "FragTrap.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;

	FragTrap	p1("yo");

	p1.beRepaired(5);
	p1.highFivesGuys();
	p1.attack("pasmoistp");
	return (0);
}
