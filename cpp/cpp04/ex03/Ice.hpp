#ifndef _Ice_hpp_
#define _Ice_hpp_

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice(void);
		Ice(Ice const & src);
		~Ice(void);
		Ice & operator=(Ice const & rhs);
	
	private:
	
};

#endif
