#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();

	public:
		void annouce() ;

	private:
		std::string	_name;
};

#endif
