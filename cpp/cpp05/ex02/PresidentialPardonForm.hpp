#ifndef _PresidentialPardonForm_hpp_
#define _PresidentialPardonForm_hpp_

#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm &	operator=(PresidentialPardonForm const & src);
	
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string	target;
};

#endif
