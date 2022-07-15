#ifndef _FragTrap_hpp_
#define _FragTrap_hpp_

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);
		FragTrap &	operator=(FragTrap const & rhs);
	
		void	highFivesGuys(void);
};

#endif
