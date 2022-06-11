#ifndef _ClapTrap_hpp_
#define _ClapTrap_hpp_

#include <iostream>

class ClapTrap {
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		ClapTrap &	operator=(ClapTrap const & src);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
	private:
		std::string	_name;
		int			_pv;
		int			_pe;
		int			_attackDmg;

};

#endif
