#ifndef _WrongCat_hpp_
#define _WrongCat_hpp_

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		~WrongCat(void);
		WrongCat &	operator=(WrongCat const & src);
};

#endif
