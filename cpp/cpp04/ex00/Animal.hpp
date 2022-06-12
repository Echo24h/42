#ifndef _Animal_hpp_
#define _Animal_hpp_

#include <iostream>

class Animal {
	public:
		Animal(void);
		Animal(std::string const type);
		Animal(Animal const & src);
		~Animal(void);
		Animal &	operator=(Animal const & src);
	
		virtual void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	type;
};

#endif
