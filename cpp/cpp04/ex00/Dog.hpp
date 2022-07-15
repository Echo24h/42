#ifndef _Dog_hpp_
#define _Dog_hpp_

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog(void);
		Dog &	operator=(Dog const & rhs);

		void	makeSound(void) const;
};

#endif
