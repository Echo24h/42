#ifndef _ClapTrap_hpp_
#define _ClapTrap_hpp_

#include <iostream>

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		ClapTrap &	operator=(ClapTrap const & src);

		void	attack(const std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
	protected:
		std::string	name;
		int			pv;
		int			pe;
		int			attackDmg;

		bool	is_alive();
		bool	has_energy();
};

#endif
