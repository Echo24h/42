#ifndef _DiamondTrap_hpp_
#define _DiamondTrap_hpp_

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap(void);

		DiamondTrap &	operator=(DiamondTrap const & rhs);

		void	whoAmI(void);

	private:
		std::string	name;
};

#endif
