#ifndef _HumanA_hpp_
#define _HumanA_hpp_

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon & wp);

	public:
		void	attack();
		void	setWeapon(Weapon& wp);

	private:
		Weapon &	_wp;
		std::string	_name;
};

#endif
