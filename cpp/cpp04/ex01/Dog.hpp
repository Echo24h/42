#ifndef _Dog_hpp_
#define _Dog_hpp_

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(Dog const & src);
		virtual ~Dog(void);
		Dog &	operator=(Dog const & src);

		void	makeSound(void) const;
		void	showIdea(int const index) const;
		void	addIdea(std::string const idea);

	private:
		Brain	*brn;
};

#endif
