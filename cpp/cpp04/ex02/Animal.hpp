#ifndef _Animal_hpp_
#define _Animal_hpp_

#include <iostream>
#include "Brain.hpp"

class Animal {
	public:
		Animal(void);
		Animal(std::string const type);
		Animal(Animal const & src);
		virtual ~Animal(void);
		Animal &	operator=(Animal const & src);
	
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;

	protected:
		std::string	type;
};

#endif
