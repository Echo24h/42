#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();

	public:
		void annouce(void);

	private:
		std::string	_name;
};


#endif
