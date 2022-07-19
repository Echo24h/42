#ifndef _Cure_hpp_
#define _Cure_hpp_

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure(void);
		Cure(Cure const & src);
		~Cure(void);
		Cure & operator=(Cure const & rhs);
	
		AMateria * 	clone(void) const;
		void		use(ICharacter& target);
};

#endif
