#ifndef _AMateria_hpp_
#define _AMateria_hpp_

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string const	type;

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		AMateria::~AMateria(void);

		AMateria & AMateria::operator=(AMateria const & rhs);

		std::string const & getType(void) const;
		virtual AMateria * clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif
