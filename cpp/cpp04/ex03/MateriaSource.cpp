#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		delete this->_materias[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	for (int i = 0; i < 4; i++) {
		delete this->_materias[i];
	}

	for (int i = 0; i < 4; i++) {
		this->_materias[i] = rhs._materias[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria * m) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] == nullptr) {
			this->_materias[i] = m->clone();
			return ;
		}
	}
}

AMateria * MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i]->getType() == type) {
			return (this->_materias[i]->clone());
		}
	}
	return (nullptr);
}

void	MateriaSource::showMaterias(void) const {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != nullptr) {
			std::cout << this->_materias[i]->getType() << std::endl;
		}
	}
}
