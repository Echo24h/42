#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	res = new Zombie[N];
	for (int i = 0; i < N; i++) {
		Zombie*	tmp = new Zombie(name);
		res[i] = *tmp;
		delete tmp;
	}
	return (res);
}