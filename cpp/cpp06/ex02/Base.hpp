#ifndef _Base_hpp_
#define _Base_hpp_

#include <iostream>

class Base {
	public:
		Base(void);
		Base(Base const & src);
		virtual ~Base(void);
		Base & operator=(Base const & src);
	
	private:
	
};

#endif
