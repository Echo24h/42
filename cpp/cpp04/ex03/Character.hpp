#ifndef _Character_hpp_
#define _Character_hpp_

#include <iostream>
#include "ICharacter.hpp"

class AMateria;

class Character: public ICharacter {
	public:
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);
		Character & operator=(Character const & rhs);

		std::string const & getName(void) const;
		void 				equip(AMateria * m);
		void				unequip(int idx);
		void				use(int idx, ICharacter & target);

	private:
		std::string const	_name;
		AMateria *			_inventory[4];
};

#endif
