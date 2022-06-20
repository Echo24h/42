#ifndef _A_hpp_
#define _A_hpp_

#include <iostream>
#include "Base.hpp"

class A: public Base {
	public:
		A(void);
		A(A const & src);
		~A(void);
		A & operator=(A const & src);
	
	private:
	
};

#endif
