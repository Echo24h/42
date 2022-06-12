#ifndef _Cat_hpp_
#define _Cat_hpp_

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);
		Cat &	operator=(Cat const & src);

		void	makeSound(void) const;
};

#endif
