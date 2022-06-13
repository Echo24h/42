#ifndef _Brain_hpp_
#define _Brain_hpp_

#include <iostream>
#include "Brain.hpp"

class Brain {
	public:
		Brain(void);
		Brain(std::string const type);
		Brain(Brain const & src);
		~Brain(void);
		Brain &	operator=(Brain const & src);
	
		void			showIdea(int const index) const;

	protected:
		std::string	ideas[100];
};

#endif
