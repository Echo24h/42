#ifndef _HumanB_hpp_
#define _HumanB_hpp_

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name) :
			_name(name) {
			_wp = nullptr;
		}

		void	attack();
		void	setWeapon(Weapon& wp);
	
	private:
		Weapon*		_wp;
		std::string	_name;
};

#endif
