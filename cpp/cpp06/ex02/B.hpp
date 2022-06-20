#ifndef _B_hpp_
#define _B_hpp_

#include <iostream>
#include "Base.hpp"

class B: public Base {
	public:
		B(void);
		B(B const & src);
		~B(void);
		B & operator=(B const & src);
	
	private:
	
};

#endif
