#ifndef _WrongAnimal_hpp_
#define _WrongAnimal_hpp_

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(std::string const type);
		WrongAnimal(WrongAnimal const & src);
		~WrongAnimal(void);
		WrongAnimal &	operator=(WrongAnimal const & src);
	
		void		makeSound(void) const;
		std::string	getType(void) const;
		
	protected:
		std::string	type;
};

#endif
