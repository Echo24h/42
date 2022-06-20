#ifndef _C_hpp_
#define _C_hpp_

#include <iostream>
#include "Base.hpp"

class C: public Base {
	public:
		C(void);
		C(C const & src);
		~C(void);
		C & operator=(C const & src);
	
	private:
	
};

#endif
