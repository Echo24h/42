#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public:
		Zombie(std::string name = "anonyme") {
			_name = name;
		}
		
		~Zombie() {
			std::cout << _name << " is gone... rip :/\n";
		}

		void annouce() ;
	private:
		std::string	_name;
};


#endif
