#include "Zombie.hpp"
#include <iostream>

Zombie *	zombieHorde(int N, std::string name);

int	main()
{
	Zombie*	zbHorde = zombieHorde(5, "yo");
	for (int i = 0; i < 5; i++) {
		zbHorde[i].annouce();
	}
	delete[] zbHorde;
	return (0);
}
