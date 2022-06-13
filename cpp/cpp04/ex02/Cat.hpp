#ifndef _Cat_hpp_
#define _Cat_hpp_

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat(void);
		Cat(Cat const & src);
		virtual ~Cat(void);
		Cat &	operator=(Cat const & src);

		void	makeSound(void) const;
		void	showIdea(int const index) const;

	private:
		Brain	*brn;
};

#endif
