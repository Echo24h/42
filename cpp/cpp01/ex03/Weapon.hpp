#ifndef _Weapon_hpp_
#define _Weapon_hpp_

#include <iostream>

class Weapon {
	public:
		Weapon(void);
		Weapon(std::string type);

	public:
		std::string const &	getType(void) const;
		void				setType(std::string newType);
	
	private:
		std::string	_type;
};

#endif
