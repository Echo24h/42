#ifndef _HumanB_hpp_
#define _HumanB_hpp_

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon & wp);

	public:
		void	attack(void);
		void	setWeapon(Weapon& wp);
	
	private:
		Weapon *	_wp;
		std::string	_name;
};

#endif
