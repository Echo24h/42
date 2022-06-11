#ifndef _Weapon_hpp_
#define _Weapon_hpp_

#include <iostream>

class Weapon {
	public:
		Weapon(std::string type) :
			_type(type) {}

		std::string&	getType();
		void			setType(std::string newType);
	
	private:
		std::string	_type;
};

#endif
