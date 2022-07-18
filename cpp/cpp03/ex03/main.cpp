#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp" 
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;
	DiamondTrap	p1;

	p1.beRepaired(5);
	p1.highFivesGuys();
	p1.attack("pasmoistp");
	p1.guardGate();
	p1.highFivesGuys();
	p1.whoAmI();
	return (0);
}
