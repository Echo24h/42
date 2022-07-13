#include "Zombie.hpp"

Zombie *	newZombie(std::string name);
void 		randomChump(std::string name);

int	main()
{
	Zombie*	zb = newZombie("yo");
	zb->annouce();
	randomChump("ktulu");
	delete zb;
	return (0);
}