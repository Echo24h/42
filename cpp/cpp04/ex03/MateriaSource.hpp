#ifndef _MateriaSource_hpp_
#define _MateriaSource_hpp_

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource {
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);

		MateriaSource & operator=(MateriaSource const & rhs);

		void 		learnMateria(AMateria * m);
		AMateria * 	createMateria(std::string const & type);
		void		showMaterias(void) const;

	private:
		AMateria *	_materias[4];
};

std::ostream &	operator<<(std::ostream &ostrm, MateriaSource const & src);

#endif
